/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:12:42 by tponutha          #+#    #+#             */
/*   Updated: 2023/11/13 20:42:33 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	FragTrap::HitPoint = 100;
	FragTrap::EnergyPoint = 100;
	FragTrap::AttackDamage = 30;
	std::cout << "FragTrap " << name << " is born with " 
			<< FragTrap::HitPoint << " HitPoint, "
			<< FragTrap::EnergyPoint << " EnergyPoint, "
			<< FragTrap::AttackDamage << " AttackDamage" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << FragTrap::name << " is die with " 
			<< FragTrap::HitPoint << " HitPoint, "
			<< FragTrap::EnergyPoint << " EnergyPoint, "
			<< FragTrap::AttackDamage << " AttackDamage" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	if (FragTrap::HitPoint <= 0 || FragTrap::EnergyPoint <= 0)
		return;
	std::cout << "FragTrap " << FragTrap::name << " want to take highfive" << std::endl;
}