/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:17:39 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/13 16:44:33 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	ScavTrap::HitPoint = 100;
	ScavTrap::EnergyPoint = 50;
	ScavTrap::AttackDamage = 20;
	std::cout << "ScavTrap " << name << " is born with " 
			<< ScavTrap::HitPoint << " HitPoint, "
			<< ScavTrap::EnergyPoint << " EnergyPoint, "
			<< ScavTrap::AttackDamage << " AttackDamage" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& object) : ClapTrap(object)
{
	ScavTrap::AttackDamage = object.AttackDamage;
	ScavTrap::EnergyPoint = object.EnergyPoint;
	ScavTrap::HitPoint = object.HitPoint;
	std::cout << "ScavTrap " << name << " is cloning via Copy Constructor " 
			<< ScavTrap::HitPoint << " HitPoint, "
			<< ScavTrap::EnergyPoint << " EnergyPoint, "
			<< ScavTrap::AttackDamage << " AttackDamage" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& object)
{
	ScavTrap::name = object.name;
	ScavTrap::EnergyPoint = object.EnergyPoint;
	ScavTrap::HitPoint = object.HitPoint;
	ScavTrap::AttackDamage = object.AttackDamage;
	std::cout << "ScavTrap " << name << " is cloning via Copy Assignment " 
			<< ScavTrap::HitPoint << " HitPoint, "
			<< ScavTrap::EnergyPoint << " EnergyPoint, "
			<< ScavTrap::AttackDamage << " AttackDamage" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << ScavTrap::name << " is die with " 
			<< ScavTrap::HitPoint << " HitPoint, "
			<< ScavTrap::EnergyPoint << " EnergyPoint, "
			<< ScavTrap::AttackDamage << " AttackDamage" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (ScavTrap::HitPoint <= 0 || ScavTrap::EnergyPoint <= 0)
		return;
	std::cout << "ScavTrap " <<  ScavTrap::name << " is now in Gate keeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (ScavTrap::HitPoint <= 0 || ScavTrap::EnergyPoint <= 0)
		return;
	std::cout << "ScavTrap " << ScavTrap::name << " attacks " << target << ", "
			<< "causing " << ScavTrap::AttackDamage << " points of damage!" << std::endl;
	ScavTrap::EnergyPoint--;
}