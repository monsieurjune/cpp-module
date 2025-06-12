/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 02:28:48 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/12 23:32:40 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <sstream>
#include <vector>
#include <iostream>

static std::vector<std::string>    sb_split(std::string const& str, char delim)
{
    std::vector<std::string>    vec;
    std::stringstream           ss(str);
    std::string                 getter;

    while (std::getline(ss, getter, delim))
    {
        if (getter.empty())
        {
            continue;
        }
        vec.push_back(getter);
    }

    return vec;
}

static size_t   sb_count(std::string const& str, char c)
{
    size_t  n = 0;

    for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
    {
        if (*it == c)
        {
            n++;
        }
    }

    return n;
}

static bool sb_is_raw_date(std::string const& str, size_t min_length, size_t max_length)
{
    if (str.length() > max_length || str.length() < min_length)
    {
        return false;
    }

    for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
    {
        if (*it < '0' || *it > '9')
        {
            return false;
        }
    }

    return true;
}

static bool sb_is_number(std::string const& str)
{
    size_t                      decimal_point_n = 0;
    std::string::const_iterator begin = str.begin();

    // skip '-'
    if (str[0] == '-')
    {
        begin++;
    }

    // check if first isn't omitted decimal or just weird decimal (9.)
    if (*begin == '.' || str[str.length() - 1] == '.')
    {
        return false;
    }

    // iterate string
    for (std::string::const_iterator it = begin; it != str.end(); it++)
    {
        if (*it >= '0' && *it <= '9')
        {
            continue;
        }
        else if (*it == '.')
        {
            decimal_point_n++;
            if (decimal_point_n > 1)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    return true;
}

static size_t   sb_to_ulong(std::string const& num)
{
    std::stringstream   ss;
    size_t              ret;

    ss << num;
    ss >> ret;

    return ret;
}

static double   sb_to_double(std::string const& num)
{
    std::stringstream   ss;
    double              ret;

    ss << num;
    ss >> ret;

    return ret;
}

BitcoinExchange::BitcoinExchange() : _isObjValid(true) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& rhs) : _mapPriceByDate(rhs.getMapPriceByDate()),\
                                                                _isObjValid(rhs.isValid())
{
}

BitcoinExchange::BitcoinExchange(std::ifstream const& dbfile)
{
    readDB(dbfile);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&    BitcoinExchange::operator=(BitcoinExchange const& rhs)
{
    if (&rhs == this)
    {
        return *this;
    }

    _mapPriceByDate = rhs.getMapPriceByDate();
    _isObjValid = rhs.isValid();

    return *this;
}

bool    BitcoinExchange::isValid() const
{
    return _isObjValid;
}

std::map<size_t, double> const&    BitcoinExchange::getMapPriceByDate() const
{
    return _mapPriceByDate;
}

size_t  BitcoinExchange::checkDateFormat(std::string const& date)
{
    std::string err_msg("bad input");

    err_msg.append(" => ");
    err_msg.append(date);

    // check '-'
    size_t  count_minus = sb_count(date, '-');

    if (count_minus != 2)
    {
        throw std::runtime_error(err_msg);
    }

    // split
    std::vector<std::string>    vec = sb_split(date, '-');

    if (vec.size() != 3)
    {
        throw std::runtime_error(err_msg);
    }

    // check raw date
    if (sb_is_raw_date(vec[0], 1, std::string::npos) && sb_is_raw_date(vec[1], 2, 2) && sb_is_raw_date(vec[2], 2, 2))
    {
        throw std::runtime_error(err_msg);
    }

    // get date (year-month-day)
    size_t  year = sb_to_ulong(vec[0]);
    size_t  month = sb_to_ulong(vec[1]);
    size_t  day = sb_to_ulong(vec[2]);
    bool    is_leap_year = false;

    // check year (NOT ABOVE OVERFLOW)
    if (year < 1 || year > (__UINT64_MAX__ / 10000))
    {
        throw std::runtime_error(err_msg);
    }

    // check month
    if (month < 1 || month > 12)
    {
        throw std::runtime_error(err_msg);
    }

    // check lower end of day
    if (day < 1)
    {
        throw std::runtime_error(err_msg);
    }

    // check upper end of day
    is_leap_year = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);

    if (month == 2)
    {
        if (is_leap_year)
        {
            if (day > 29)
            {
                throw std::runtime_error(err_msg);
            }
        }
        else
        {
            if (day > 28)
            {
                throw std::runtime_error(err_msg);
            }
        }
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day > 31)
        {
            throw std::runtime_error(err_msg);
        }
    }
    else
    {
        if (day > 30)
        {
            throw std::runtime_error(err_msg);
        }
    }

    return (year * 10000) + (month * 100) + day;
}

void    BitcoinExchange::checkCSVHeader(std::string const& line)
{
    std::string                 err_msg("bad header");
    std::vector<std::string>    vec = sb_split(line, ',');

    err_msg.append(" => ");
    err_msg.append(line);

    if (vec.size() != 2)
    {
        throw std::runtime_error(err_msg);
    }

    if (vec[0] != "date")
    {
        throw std::runtime_error(err_msg);
    }

    if (vec[1] != "exchange_rate")
    {
        throw std::runtime_error(err_msg);
    }
}

void    BitcoinExchange::checkCSVLine(std::string const& line)
{
    std::vector<std::string>    vec = sb_split(line, ',');

    if (vec.size() != 2)
    {
        return;
    }

    try
    {
        // check date
        size_t  date = checkDateFormat(vec[0]);

        // check raw exchange_rate
        if (!sb_is_number(vec[1]))
        {
            return;
        }

        // check exchange_rate number
        double  price = sb_to_double(vec[1]);

        if (price <= 0.0 || price > 2147483647.0)
        {
            return;
        }

        // add date,exchange_rate to stl
        if (_mapPriceByDate.find(date) == _mapPriceByDate.end())
        {
            _mapPriceByDate[date] = price;
        }
    }
    catch (std::exception const&)
    {
        // ignore
        return;
    }
}

void    BitcoinExchange::checkInputHeader(std::string const& line)
{
    std::string                 bad_line_err;
    std::vector<std::string>    vec = sb_split(line, ' ');

    // check vec
    if (vec.size() != 3)
    {
        throw std::runtime_error(bad_line_err);
    }

    // check main delim
    if (vec[1] != "|")
    {
        throw std::runtime_error(bad_line_err);
    }

    // check date
    if (vec[0] != "date")
    {
        throw std::runtime_error(bad_line_err);
    }

    // check value
    if (vec[0] != "value")
    {
        throw std::runtime_error(bad_line_err);
    }
}

void    BitcoinExchange::checkInputLine(std::string const& line)
{
    std::string                 bad_line_err;
    std::vector<std::string>    vec = sb_split(line, ' ');

    // check vec
    if (vec.size() != 3)
    {
        throw std::runtime_error(bad_line_err);
    }

    // check main delim
    if (vec[1] != "|")
    {
        throw std::runtime_error(bad_line_err);
    }

    // check date
    size_t  date = checkDateFormat(vec[0]);

    // check value
    if (!sb_is_number(vec[2]))
    {
        throw std::runtime_error(bad_line_err);
    }

    // get value
    double  value = sb_to_double(vec[2]);

    if (value < 0.0 || value > 2147483647.0)
    {
        throw std::runtime_error(bad_line_err);
    }

    // get right price for right time
    std::map<size_t, double>::iterator  it = _mapPriceByDate.lower_bound(date);

    if (it == _mapPriceByDate.end())
    {
        // too future date
        it--;
    }
    else if (it != _mapPriceByDate.begin())
    {
        // decrement back to recent past, not recent future
        if (it->first > date)
        {
            it--;
        }
    }

    // print date => value = value * price
    std::cout << date / 10000 << '-' 
                << (date % 10000) / 100 << '-' 
                << date % 100 << " => "
                << value << " = " << value * it->second
                << std::endl;
}