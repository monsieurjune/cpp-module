/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:45:50 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/20 11:57:42 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>
#include <iostream>
#include <cmath>

typedef enum e_type
{
    IMPOSSIBLE,
    CHAR,
    INT,
    FLOAT,
    DOUBLE
}   t_type;

static inline bool  sb_is_int(std::string const& str)
{
    std::string::const_iterator begin = str.begin();

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

static inline bool  sb_is_special_floating(std::string const& str)
{
    if (str == "-inf" || str == "-inff")
    {
        return true;
    }
    else if (str == "+inf" || str == "+inff")
    {
        return true;
    }
    else if (str == "nan" || str == "nanf")
    {
        return true;
    }
    return false;
}

static inline bool  sb_is_double(std::string const& str)
{
    size_t                      decimal = 0;
    std::string::const_iterator begin = str.begin();

    if (sb_is_special_floating(str))
    {
        return true;
    }

    if (str[0] == '.')
    {
        return false;
    }

    if (str[0] == '-' || str[0] == '+')
    {
        begin++;
    }

    for (std::string::const_iterator it = begin; it != str.end(); it++)
    {
        if (*it >= '0' && *it <= '9')
        {
            continue;
        }
        else if (*it == '.')
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

static inline bool  sb_is_float(std::string const& str)
{
    if (str[str.length() - 1] != 'f')
    {
        return false;
    }

    return sb_is_double(str);
}

static inline size_t   sb_find_first_non_ws_char(std::string const& str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] != '\r' && str[i] != '\n' && str[i] != ' ' && str[i] != '\v' && str[i] != '\t' && str[i] != '\f')
        {
            return i;
        }
    }

    return std::string::npos;
}

static inline size_t   sb_find_last_non_ws_char(std::string const& str)
{
    for (size_t i = str.length() - 1; i > 0; i--)
    {
        if (str[i] != '\r' && str[i] != '\n' && str[i] != ' ' && str[i] != '\v' && str[i] != '\t' && str[i] != '\f')
        {
            return i;
        }
    }

    // check i = 0
    if (str[0] != '\r' && str[0] != '\n' && str[0] != ' ' && str[0] != '\v' && str[0] != '\t' && str[0] != '\f')
    {
        return 0;
    }

    return std::string::npos;
}

static inline std::string   sb_trimming_string(std::string const& str)
{
    size_t  first = sb_find_first_non_ws_char(str);
    size_t  last = sb_find_last_non_ws_char(str);

    if (first == std::string::npos || last == std::string::npos)
    {
        return str;
    }

    return str.substr(first, last - first + 1);
}

static inline int   sb_to_int(std::string const& str)
{
    int                 ret;
    std::stringstream   ss;

    ss << str;
    ss >> ret;

    return ret;
}

static inline float sb_to_special_float(std::string const& str)
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

static inline float sb_to_float(std::string const& str)
{
    if (sb_is_special_floating(str))
    {
        return sb_to_special_float(str);
    }

    // convert normal case
    float               ret;
    std::stringstream   ss;

    ss << str;
    ss >> ret;

    return ret;
}

static inline double sb_to_double(std::string const& str)
{
    if (sb_is_special_floating(str))
    {
        return static_cast<double>(sb_to_special_float(str));
    }

    // convert normal case
    double              ret;
    std::stringstream   ss;

    ss << str;
    ss >> ret;

    return ret;
}

static inline void  sb_print_char(char c, t_type type, std::string const& str)
{
    std::cout << "char: ";

    if (type == IMPOSSIBLE || sb_is_special_floating(str))
    {
        std::cout << "impossible";
    }
    else if (c < '\x20' || c > '\x7e')
    {
        std::cout << "Non displayable";
    }
    else
    {
        std::cout << c;
    }
    std::cout << std::endl;
}

static inline void  sb_print_int(int i, t_type type, std::string const& str)
{
    std::cout << "int: ";

    if (type == IMPOSSIBLE || sb_is_special_floating(str))
    {
        std::cout << "impossible";
    }
    else
    {
        std::cout << i;
    }
    std::cout << std::endl;
}

static inline void  sb_print_float(float f, t_type type)
{
    std::cout << "float: ";

    if (type == IMPOSSIBLE)
    {
        std::cout << "impossible" << std::endl;
        return;
    }

    std::cout << f;
    if (std::floor(f) == f)
    {
        std::cout << ".0";
    }
    std::cout << "f" << std::endl;
}

static inline void  sb_print_double(double d, t_type type)
{
    std::cout << "double: ";

    if (type == IMPOSSIBLE)
    {
        std::cout << "impossible" << std::endl;
        return;
    }

    std::cout << d;
    if (std::floor(d) == d)
    {
        std::cout << ".0";
    }
    std::cout << std::endl;
}

void    ScalarConverter::convert(std::string const& str)
{
    t_type  type = IMPOSSIBLE;
    char    c;
    int     i;
    float   f;
    double  d;

    // trim space out
    std::string trimmed_str = sb_trimming_string(str);

    // check type
    if (trimmed_str.length() == 1 && (trimmed_str[0] < '0' || trimmed_str[0] > '9'))
    {
        c = trimmed_str[0];
        type = CHAR;
    }
    else if (sb_is_int(trimmed_str))
    {
        i = sb_to_int(trimmed_str);
        type = INT;
    }
    else if (sb_is_float(trimmed_str))
    {
        f = sb_to_float(trimmed_str);
        type = FLOAT;
    }
    else if (sb_is_double(trimmed_str))
    {
        d = sb_to_double(trimmed_str);
        type = DOUBLE;
    }

    // check state
    switch (type)
    {
        case CHAR:
            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);
            break;

        case INT:
            c = static_cast<char>(i);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
            break;

        case FLOAT:
            c = static_cast<char>(f);
            i = static_cast<int>(f);
            d = static_cast<double>(f);
            break;

        case DOUBLE:
            c = static_cast<char>(d);
            i = static_cast<int>(d);
            f = static_cast<float>(d);
            break;

        default:
            break;
    }

    // print
    sb_print_char(c, type, trimmed_str);
    sb_print_int(i, type, trimmed_str);
    sb_print_float(f, type);
    sb_print_double(d, type);
}