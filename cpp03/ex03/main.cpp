/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:13:22 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/13 23:07:25 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

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
		FragTrap	c("C");
		
		c.takeDamage(49);
		c.beRepaired(10);
		c.attack("Whatever");
		c.highFivesGuys();
	}

	std::cout << "----------------------------------" << std::endl;
	{
		DiamondTrap	d("D");

		d.takeDamage(69);
		d.beRepaired(100);
		d.attack("Itself");
		d.whoAmI();
	}

	std::cout << "----------------------------------" << std::endl;
	{
		DiamondTrap	f("F");

		f.takeDamage(1);
		f.beRepaired(1);
		f.attack("EveryWhere");
		f.highFivesGuys();
	}

	std::cout << "----------------------------------" << std::endl;
	{
		DiamondTrap	e1("E1");
		DiamondTrap	e2("E2");

		e2 = e1;
		e1.takeDamage(7667832);
		e1.whoAmI();
		e1.guardGate();
		e1.highFivesGuys();
		e2.whoAmI();
		e2.guardGate();
		e2.highFivesGuys();
	}
	return 0;
}