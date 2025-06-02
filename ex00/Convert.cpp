/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:37:39 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/03 01:51:18 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include <sstream>
#include <cmath>

static inline bool  sb_iterate_decimal(std::string::const_iterator begin, std::string::const_iterator end)
{
    size_t  decimal = 0;

    // no omit first zero (e.g. '.05')
    if (*begin == '.')
    {
        return false;
    }

    // skip sign
    if (*begin == '-' || *begin == '+')
    {
        begin++;
    }

    // iterate
    for (std::string::const_iterator it = begin; it != end; it++)
    {
        if (*it >= '0' && *it <= '9')
        {
            continue;
        }
        else if  (*it == '.')
        {
            decimal++;
            if (decimal > 1)
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

int to_int(std::string const& str)
{
    int                 ret;
    std::stringstream   ss;

    ss << str;
    ss >> ret;

    return ret;
}

float   to_float(std::string const& str)
{
    // special float
    if (str == "-inff" || str == "+inff" || str == "nanf")
    {
        return to_special_float(str);
    }

    // normal float
    float               ret;
    std::stringstream   ss;

    ss << str;
    ss >> ret;

    return ret;
}

float   to_special_float(std::string const& str)
{
    if (str == "-inf" || str == "-inff")
    {
        return -INFINITY;
    }
    else if (str == "+inf" || str == "+inff")
    {
        return INFINITY;
    }
    else if (str == "nan" || str == "nanf")
    {
        return NAN;
    }
    return -NAN;
}

double  to_double(std::string const& str)
{
    // special float
    if (str == "-inff" || str == "+inff" || str == "nanf")
    {
        return to_special_double(str);
    }

    // normal double
    double              ret;
    std::stringstream   ss;

    ss << str;
    ss >> ret;

    return ret;
}

double  to_special_double(std::string const& str)
{
    return static_cast<double>(to_special_float(str));
}

bool    is_int(std::string const& str)
{
    std::string::const_iterator begin = str.begin();

    // skip sign
    if (str[0] == '-' || str[0] == '+')
    {
        begin++;
    }

    for (std::string::const_iterator it = begin; it != str.end(); it++)
    {
        if (*it < '0' || *it > '9')
        {
            return false;
        }
    }

    return true;
}

bool    is_float(std::string const& str)
{
    std::string::const_iterator begin = str.begin();
    std::string::const_iterator end = str.end() - 1;

    // must has 'f' suffix
    if (str[str.length() - 1] != 'f')
    {
        return false;
    }

    return sb_iterate_decimal(begin, end);
}

bool    is_special_float(std::string const& str)
{
    return (str == "-inff" || str == "+inff" || str == "nanf");
}

bool    is_double(std::string const& str)
{
    std::string::const_iterator begin = str.begin();
    std::string::const_iterator end = str.end();

    return sb_iterate_decimal(begin, end);
}

bool    is_special_double(std::string const& str)
{
    return (str == "-inf" || str == "+inf" || str == "nan");
}