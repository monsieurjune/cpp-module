/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseBureaucraticException.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:21:19 by tponutha          #+#    #+#             */
/*   Updated: 2025/04/03 08:30:44 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseBureaucraticException.hpp"

BaseBureaucraticException::BaseBureaucraticException(const char* msg)
{
    _msg.assign(msg);
}

BaseBureaucraticException::BaseBureaucraticException(std::string const& msg)
{
    _msg = msg;
}

BaseBureaucraticException::~BaseBureaucraticException() throw() {}

const char* BaseBureaucraticException::what() const throw()
{
    return _msg.c_str();
}