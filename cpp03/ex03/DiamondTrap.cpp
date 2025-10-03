/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:27:48 by tponutha          #+#    #+#             */
/*   Updated: 2023/11/13 20:50:20 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	FragTrap::HitPoint = 100;
	ScavTrap::EnergyPoint = 50;
	FragTrap::AttackDamage = 30;
	std::cout << "DiamondTrap " << DiamondTrap::name << " is born with " 
			<< DiamondTrap::HitPoint << " HitPoint, "
			<< DiamondTrap::EnergyPoint << " EnergyPoint, "
			<< DiamondTrap::AttackDamage << " AttackDamage" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " is die with " 
			<< DiamondTrap::HitPoint << " HitPoint, "
			<< DiamondTrap::EnergyPoint << " EnergyPoint, "
			<< DiamondTrap::AttackDamage << " AttackDamage" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	if (DiamondTrap::HitPoint <= 0 || DiamondTrap::EnergyPoint <= 0)
		return;
	std::cout << "I am " << DiamondTrap::name << std::endl;
}