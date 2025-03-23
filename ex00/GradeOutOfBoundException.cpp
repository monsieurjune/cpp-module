/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeOutOfBoundException.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 06:51:19 by tponutha          #+#    #+#             */
/*   Updated: 2025/03/24 03:47:33 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GradeOutOfBoundException.hpp"

GradeOutOfBoundException::GradeOutOfBoundException(const char* msg)
{
    _msg.assign(msg);
}

GradeOutOfBoundException::GradeOutOfBoundException(std::string const& msg)
{
    _msg.assign(msg.c_str());
}

GradeOutOfBoundException::~GradeOutOfBoundException() throw() {}

const char* GradeOutOfBoundException::what() const throw()
{
    return _msg.c_str();
}