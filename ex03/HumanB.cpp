/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:35:18 by tponutha          #+#    #+#             */
/*   Updated: 2023/10/27 03:28:52 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack()
{
	std::cout << HumanB::name << " attacks with their " << *HumanB::pwpon << std::endl;
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