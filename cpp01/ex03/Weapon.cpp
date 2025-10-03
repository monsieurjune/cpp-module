/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:35:31 by tponutha          #+#    #+#             */
/*   Updated: 2023/10/27 03:28:11 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string	&Weapon::getType(void)
{
	return Weapon::type;
}

void	Weapon::setType(std::string type)
{
	Weapon::type = type;
}

Weapon::Weapon(std::string type)
{
	Weapon::type = type;
}