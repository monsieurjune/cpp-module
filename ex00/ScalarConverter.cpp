/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:45:50 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/03 01:54:15 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "Convert.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

typedef enum e_type
{
    IMPOSSIBLE,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    SPECIAL_FLOAT,
    SPECIAL_DOUBLE
}   t_type;

static inline void  sb_assign(char base, int *i, float *f, double *d)
{
    *i = static_cast<int>(base);
    *f = static_cast<float>(base);
    *d = static_cast<double>(base);
}

static inline void  sb_assign(int base, char *c, float *f, double *d)
{
    *c = static_cast<char>(base);
    *f = static_cast<float>(base);
    *d = static_cast<double>(base);
}

static inline void  sb_assign(float base, char *c, int *i, double *d)
{
    *c = static_cast<char>(base);
    *i = static_cast<int>(base);
    *d = static_cast<double>(base);
}

static inline void  sb_assign(double base, char *c, int *i, float *f)
{
    *c = static_cast<char>(base);
    *i = static_cast<int>(base);
    *f = static_cast<float>(base);
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

static inline void  sb_print_char(char c, t_type type)
{
    std::stringstream   ss;

    ss << "char: ";
    if (type == IMPOSSIBLE || type == SPECIAL_FLOAT || type == SPECIAL_DOUBLE)
    {
        ss << "impossible";
    }
    else if (c < '\x20' || c > '\x7e')
    {
        ss << "Non displayable";
    }
    else
    {
        ss << '\'';
        ss << c;
        ss << '\'';
    }

    // print
    std::cout << ss.str() << std::endl;
}

static inline void  sb_print_int(int i, t_type type)
{
    std::stringstream   ss;

    ss << "int: ";
    if (type == IMPOSSIBLE || type == SPECIAL_FLOAT || type == SPECIAL_DOUBLE)
    {
        ss << "impossible";
    }
    else
    {
        ss << i;
    }

    // print
    std::cout << ss.str() << std::endl;
}

static inline void  sb_print_float(float f, t_type type)
{
    std::stringstream   ss;

    ss << "float: ";
    if (type == IMPOSSIBLE)
    {
        ss << "impossible";
    }
    else if (type == SPECIAL_FLOAT || type == SPECIAL_DOUBLE)
    {
        ss << f;
        ss << "f";
    }
    else
    {
        ss << f;
        if (std::floor(f) == f)
        {
            ss << ".0";
        }
        ss << "f";
    }

    // print
    std::cout << ss.str() << std::endl;
}

static inline void  sb_print_double(double d, t_type type)
{
    std::stringstream   ss;

    ss << "double: ";
    if (type == IMPOSSIBLE)
    {
        ss << "impossible";
    }
    else if (type == SPECIAL_FLOAT || type == SPECIAL_DOUBLE)
    {
        ss << d;
    }
    else
    {
        ss << d;
        if (std::floor(d) == d)
        {
            ss << ".0";
        }
    }

    // print
    std::cout << ss.str() << std::endl;
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
        type = CHAR;
        c = trimmed_str[0];
        sb_assign(c, &i, &f, &d);
    }
    else if (is_int(trimmed_str))
    {
        type = INT;
        i = to_int(trimmed_str);
        sb_assign(i, &c, &f, &d);
    }
    else if (is_float(trimmed_str))
    {
        type = FLOAT;
        f = to_float(trimmed_str);
        sb_assign(f, &c, &i, &d);
    }
    else if (is_double(trimmed_str))
    {
        type = DOUBLE;
        d = to_double(trimmed_str);
        sb_assign(d, &c, &i, &f);
    }
    else if (is_special_float(trimmed_str))
    {
        type = SPECIAL_FLOAT;
        f = to_special_float(trimmed_str);
        sb_assign(f, &c, &i, &d);
    }
    else if (is_special_double(trimmed_str))
    {
        type = SPECIAL_DOUBLE;
        d = to_special_double(trimmed_str);
        sb_assign(d, &c, &i, &f);
    }

    // print
    sb_print_char(c, type);
    sb_print_int(i, type);
    sb_print_float(f, type);
    sb_print_double(d, type);
}