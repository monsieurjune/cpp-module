/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:13:22 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/13 22:36:37 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
// #include <std

int	main()
{
	{
		ClapTrap	a("A");

		a.takeDamage(9);
		a.beRepaired(1);
		a.attack("B");
		for (int i = 0; i < 10; i++)
		{
			a.attack("B");
		}
	}

	std::cout << "----------------------------------" << std::endl;
	{
		ScavTrap	b("B");
		
		b.takeDamage(49);
		b.beRepaired(10);
		b.attack("A");
		b.guardGate();
	}

	std::cout << "----------------------------------" << std::endl;
	{
		ScavTrap	c("C");
		ScavTrap	c_clone("D");
		// ScavTrap	c_clone(c);

		c_clone = c;
		c.takeDamage(100000);
		c.guardGate();
		c_clone.guardGate();
	}
	return 0;
}