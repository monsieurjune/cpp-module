/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:13:13 by tponutha          #+#    #+#             */
/*   Updated: 2023/11/13 18:15:24 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	ClapTrap::name = name;
	ClapTrap::HitPoint = 10;
	ClapTrap::EnergyPoint = 10;
	ClapTrap::AttackDamage = 0;
}

void	ClapTrap::attack(const std::string& target)
{
	if (ClapTrap::HitPoint <= 0 || ClapTrap::EnergyPoint <= 0)
		return;
	std::cout << "ClapTrap " << ClapTrap::name << " attacks " << target << ", ";
	std::cout << "causing " << ClapTrap::AttackDamage << " points of damage!" << std::endl;
	ClapTrap::EnergyPoint--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (ClapTrap::HitPoint <= 0 || ClapTrap::EnergyPoint <= 0)
		return;
	ClapTrap::HitPoint -= amount;
	std::cout << "ClapTrap " << ClapTrap::name << " take " << amount << " damage, ";
	std::cout << "causing ClapTrap " << ClapTrap::name << " has " << ClapTrap::HitPoint;
	std::cout << " Hitpoint left " << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (ClapTrap::HitPoint <= 0 || ClapTrap::EnergyPoint <= 0)
		return;
	ClapTrap::HitPoint += amount;
	ClapTrap::EnergyPoint--;
	std::cout << "ClapTrap " << ClapTrap::name << " repair itself with " << amount << " point, ";
	std::cout << "causing ClapTrap " << ClapTrap::name << " has " << ClapTrap::HitPoint << " Hitpoint, ";
	std::cout << "and has " << ClapTrap::EnergyPoint << " Energy left" << std::endl;
}