/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 02:28:48 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/13 10:45:26 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <fstream>

double  BitcoinExchange::_min_value = 0.0;
double  BitcoinExchange::_max_value = 1000.0;

static inline void  sb_get_token(std::stringstream& ss, std::string& getter, char delim, std::string const& err_msg)
{
    if (!std::getline(ss, getter, delim))
    {
        throw std::runtime_error(err_msg);
    }
}

static inline void sb_throw(bool condition, std::runtime_error const& e)
{
    if (condition)
    {
        throw e;
    }
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

BitcoinExchange::BitcoinExchange() : _isObjValid(false) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& rhs) : _mapPriceByDate(rhs.getMapPriceByDate()),\
                                                                _isObjValid(rhs.isValid())
{
}

BitcoinExchange::BitcoinExchange(std::string const& filename)
{
    readDB(filename);
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
    std::string         err_msg = std::string("bad input => ") + date;
    std::runtime_error  e(err_msg);
    bool                is_valid_raw_date = true;
    bool                is_leap_year = false;
    bool                is_invalid_day = false;

    // check '-'
    sb_throw(sb_count(date, '-') != 2, e);

    // get raw data
    std::stringstream   ss(date);
    std::string         raw_year;
    std::string         raw_month;
    std::string         raw_day;

    sb_get_token(ss, raw_year, '-', err_msg);
    sb_get_token(ss, raw_month, '-', err_msg);
    sb_get_token(ss, raw_day, '-', err_msg);

    // check raw date
    is_valid_raw_date &= sb_is_raw_date(raw_year, 1, std::string::npos);
    is_valid_raw_date &= sb_is_raw_date(raw_month, 2, 2);
    is_valid_raw_date &= sb_is_raw_date(raw_day, 2, 2);
    sb_throw(!is_valid_raw_date, e);

    // get date (year-month-day)
    size_t  year = sb_to_ulong(raw_year);
    size_t  month = sb_to_ulong(raw_month);
    size_t  day = sb_to_ulong(raw_day);

    // check year (NOT ABOVE OVERFLOW)
    sb_throw(year < 1 || year > (__UINT64_MAX__ / 10000), e);

    // check month
    sb_throw(month < 1 || month > 12, e);

    // check lower end of day
    sb_throw(day < 1, e);

    // check upper end of day
    is_leap_year = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);

    if (month == 2)
    {
        is_invalid_day = day > (is_leap_year ? 29 : 28);
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        is_invalid_day = day > 31;
    }
    else
    {
        is_invalid_day = day > 30;
    }
    sb_throw(is_invalid_day, e);

    return (year * 10000) + (month * 100) + day;
}

void    BitcoinExchange::checkCSVHeader(std::string const& line)
{
    std::stringstream   ss(line);
    std::string         err_msg = std::string("bad CSV header => ") + line;
    std::runtime_error  e(err_msg);
    std::string         raw_date_header;
    std::string         raw_exchange_rate_header;

    // check delim
    sb_throw(sb_count(line, ',') != 1, e);

    // ger raw data
    sb_get_token(ss, raw_date_header, ',', err_msg);
    sb_get_token(ss, raw_exchange_rate_header, ',', err_msg);

    // check header
    sb_throw(raw_date_header != "date", e);
    sb_throw(raw_exchange_rate_header != "exchange_rate", e);
}

void    BitcoinExchange::checkCSVLine(std::string const& line)
{
    std::string         err_msg;
    std::stringstream   ss(line);
    std::string         raw_date;
    std::string         raw_exchange_rate;

    // check delim
    if (sb_count(line, ',') != 1)
    {
        return;
    }

    try
    {
        // ger raw data
        sb_get_token(ss, raw_date, ',', err_msg);
        sb_get_token(ss, raw_exchange_rate, ',', err_msg);

        // check date
        size_t  date = checkDateFormat(raw_date);
        double  price;

        // check raw exchange_rate
        if (!sb_is_number(raw_exchange_rate))
        {
            return;
        }

        // check exchange_rate number
        price = sb_to_double(raw_exchange_rate);

        // too small
        if (price < 0.0)
        {
            return;
        }

        // add date,exchange_rate to stl, if doesn't exist
        if (_mapPriceByDate.find(date) == _mapPriceByDate.end())
        {
            _mapPriceByDate[date] = price;
        }
    }
    catch (std::exception const&)
    {
        return; // ignore
    }
}

void    BitcoinExchange::checkInputHeader(std::string const& line)
{
    std::stringstream   ss(line);
    std::string         bad_line_err = std::string("bad input header => ") + line;
    std::runtime_error  e(bad_line_err);
    std::string         raw_date_header;
    std::string         raw_delim_header;
    std::string         raw_value_header;

    // check delim
    sb_throw(sb_count(line, ' ') != 2, e);

    // get raw data
    sb_get_token(ss, raw_date_header, ' ', bad_line_err);
    sb_get_token(ss, raw_delim_header, ' ', bad_line_err);
    sb_get_token(ss, raw_value_header, ' ', bad_line_err);

    // check header
    sb_throw(raw_date_header != "date", e);
    sb_throw(raw_delim_header != "|", e);
    sb_throw(raw_value_header != "value", e);
}

void    BitcoinExchange::checkInputLine(std::string const& line)
{
    std::stringstream   ss(line);
    std::string         bad_line_err = std::string("bad input => ") + line;
    std::runtime_error  e(bad_line_err);
    std::runtime_error  e_neg("not a positive number.");
    std::runtime_error  e_too_much("too large a number.");
    std::string         raw_date;
    std::string         raw_delim;
    std::string         raw_value;
    size_t              date;
    double              value;
    double              price;

    try
    {
        // check delim
        sb_throw(sb_count(line, ' ') != 2, e);

        // get raw data
        sb_get_token(ss, raw_date, ' ', bad_line_err);
        sb_get_token(ss, raw_delim, ' ', bad_line_err);
        sb_get_token(ss, raw_value, ' ', bad_line_err);

        // check main delim
        sb_throw(raw_delim != "|", e);

        // check date
        date = checkDateFormat(raw_date);

        // check value
        sb_throw(!sb_is_number(raw_value), e);

        // get value
        value = sb_to_double(raw_value);
        sb_throw(value < _min_value, e_neg);
        sb_throw(value > _max_value, e_too_much);

        // get right price for right time
        price = getExactOrNearestPastPrice(date);

        // print date => value = value * price
        std::cout << date / 10000 << '-' 
                    << (((date % 10000) / 100) > 10 ? "" : "0")
                    << (date % 10000) / 100 << '-' 
                    << ((date % 100) > 10 ? "" : "0")
                    << date % 100 << " => "
                    << value << " = " << value * price
                    << std::endl;
    }
    catch (std::exception const& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

double  BitcoinExchange::getExactOrNearestPastPrice(size_t date)
{
    std::string         err_msg("Database is Empty.");
    std::runtime_error  e(err_msg);

    // do nothing, if DB is empty
    sb_throw(_mapPriceByDate.empty(), e);

    // normal part
    std::map<size_t, double>::iterator  it = _mapPriceByDate.lower_bound(date);

    if (it == _mapPriceByDate.end())
    {
        it--; // too future date, get most recent one
    }
    else if (it != _mapPriceByDate.begin() && it->first > date)
    {
        // decrement back to recent past, not recent future
        // because lower_bound() get either exact date or recent future date
        // in this case, the recent future
        it--;
    }

    return it->second;
}

void    BitcoinExchange::readDB(std::string const& db_file)
{
    std::ifstream   file(db_file.c_str());

    if (!file.is_open())
    {
        std::cout << "Error: could not open DB file." << std::endl;
        file.close();
        return;
    }

    // after open file
    std::string line;

    // read CSV Header
    if (!std::getline(file, line))
    {
        std::cout << "Error: could not read DB file." << std::endl;
        file.close();
        return;
    }

    try
    {
        // read header
        checkCSVHeader(line);

        // read whole file
        while (std::getline(file, line))
        {
            checkCSVLine(line);
        }

        _isObjValid = true;
    }
    catch (std::exception const& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        _isObjValid = false;
    }
    file.close();
}

void    BitcoinExchange::analyze(std::string const& input_file)
{
    // check db vallidation
    if (!_isObjValid)
    {
        return;
    }

    // open file
    std::ifstream   file(input_file.c_str());

    if (!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        file.close();
        return;
    }

    // after open file
    std::string line;

    // read input header
    if (!std::getline(file, line))
    {
        std::cout << "Error: could not read file." << std::endl;
        file.close();
        return;
    }

    try
    {
        // read header
        checkInputHeader(line);

        // read whole file
        while (std::getline(file, line))
        {
            checkInputLine(line);
        }
    }
    catch (std::exception const& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    file.close();
}