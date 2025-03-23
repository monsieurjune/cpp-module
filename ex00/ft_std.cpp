/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_std.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 01:12:02 by tponutha          #+#    #+#             */
/*   Updated: 2025/03/24 02:24:50 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Project Header
#include "ft_std.hpp"

// CPP Header
#include <sstream>

namespace ft_std
{

std::string	itoa(long num)
{
	std::ostringstream oss;

	oss << num;
	return oss.str();
}

}