/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 02:28:48 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/12 01:53:03 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <sstream>
#include <vector>

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

static bool sb_is_raw_date(std::string const& str, size_t max_length)
{
    if (str.length() > max_length)
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

static ssize_t  sb_to_long(std::string const& num)
{
    std::stringstream   ss;
    ssize_t             ret;

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

std::map<std::string, double> const&    BitcoinExchange::getMapPriceByDate() const
{
    return _mapPriceByDate;
}

void    BitcoinExchange::checkDateFormat(std::string const& date)
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
    if (sb_is_raw_date(vec[0], std::string::npos) && sb_is_raw_date(vec[1], 2) && sb_is_raw_date(vec[2], 2))
    {
        throw std::runtime_error(err_msg);
    }

    // get date (year-month-day)
    ssize_t year = sb_to_long(vec[0]);
    ssize_t month = sb_to_long(vec[1]);
    ssize_t day = sb_to_long(vec[2]);
    bool    is_leap_year = false;

    // check year
    if (year < 1)
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
}