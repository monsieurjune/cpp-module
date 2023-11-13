/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:13:13 by tponutha          #+#    #+#             */
/*   Updated: 2023/11/13 20:42:50 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	ClapTrap::name = name;
	ClapTrap::HitPoint = 10;
	ClapTrap::EnergyPoint = 10;
	ClapTrap::AttackDamage = 0;
	std::cout << "ClapTrap " << name << " is born with " 
			<< ClapTrap::HitPoint << " HitPoint, "
			<< ClapTrap::EnergyPoint << " EnergyPoint, "
			<< ClapTrap::AttackDamage << " AttackDamage" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << ClapTrap::name << " is die with " 
			<< ClapTrap::HitPoint << " HitPoint, "
			<< ClapTrap::EnergyPoint << " EnergyPoint, "
			<< ClapTrap::AttackDamage << " AttackDamage" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (ClapTrap::HitPoint <= 0 || ClapTrap::EnergyPoint <= 0)
		return;
	std::cout << "ClapTrap " << ClapTrap::name << " attacks " << target << ", "
			<< "causing " << ClapTrap::AttackDamage << " points of damage!" << std::endl;
	ClapTrap::EnergyPoint--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (ClapTrap::HitPoint <= 0 || ClapTrap::EnergyPoint <= 0)
		return;
	ClapTrap::HitPoint -= amount;
	std::cout << "ClapTrap " << ClapTrap::name << " take " << amount << " damage, "
			<< "causing ClapTrap " << ClapTrap::name << " has " << ClapTrap::HitPoint
			<< " Hitpoint left " << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (ClapTrap::HitPoint <= 0 || ClapTrap::EnergyPoint <= 0)
		return;
	ClapTrap::HitPoint += amount;
	ClapTrap::EnergyPoint--;
	std::cout << "ClapTrap " << ClapTrap::name << " repair itself with " << amount << " point, "
			<< "causing ClapTrap " << ClapTrap::name << " has " << ClapTrap::HitPoint << " Hitpoint, "
			<< "and has " << ClapTrap::EnergyPoint << " Energy left" << std::endl;
}