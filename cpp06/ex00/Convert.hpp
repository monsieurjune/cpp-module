/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:37:42 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/03 00:33:14 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONVERT_HPP__
#define __CONVERT_HPP__
#include <string>

// to
int     to_int(std::string const& str);
float   to_float(std::string const& str);
float   to_special_float(std::string const& str);
double  to_double(std::string const& str);
double  to_special_double(std::string const& str);

// is
bool    is_int(std::string const& str);
bool    is_float(std::string const& str);
bool    is_double(std::string const& str);
bool    is_special_float(std::string const& str);
bool    is_special_double(std::string const& str);

#endif