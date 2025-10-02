/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Format.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 02:08:44 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/03 02:20:59 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Format.hpp"

std::string sb_replace_whitespace(std::string const& str)
{
    std::string replaced_str;

    for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
    {
        if (*it == '\r' || *it == '\n' || *it == '\v' || *it == '\t' || *it == '\f')
        {
            replaced_str.push_back(' ');
        }
        else
        {
            replaced_str.push_back(*it);
        }
    }

    return replaced_str;
}

std::string trim_whitespace(std::string const& str)
{
    // in case of empty
    if (str.empty())
    {
        return str;
    }

    // normal case
    std::string replaced_str = sb_replace_whitespace(str);
    size_t      first = replaced_str.find_first_not_of(' ');
    size_t      last = replaced_str.find_last_not_of(' ');

    return replaced_str.substr(first, last - first + 1);
}