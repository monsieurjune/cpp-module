/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:35:18 by tponutha          #+#    #+#             */
/*   Updated: 2023/10/27 03:35:15 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack()
{
	if (HumanB::pwpon == NULL)
	{
		std::cout << HumanB::name << " has no weapon" << std::endl;
	}
	else
	{
		std::cout << HumanB::name << " attacks with their " << *HumanB::pwpon << std::endl;
	}
}

void	HumanB::setWeapon(Weapon &etc)
{
	HumanB::pwpon = &etc.getType();
}

HumanB::HumanB(std::string name)
{
	HumanB::name = name;
	HumanB::pwpon = NULL;
}