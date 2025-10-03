/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:13:22 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/13 22:54:27 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

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
		FragTrap	b("B");
		
		b.takeDamage(49);
		b.beRepaired(10);
		b.attack("A");
		b.highFivesGuys();
	}

	std::cout << "----------------------------------" << std::endl;
	{
		FragTrap	c("C");
		FragTrap	d("D");
		FragTrap	e("E");

		d = c;
		c.highFivesGuys();
		d.highFivesGuys();
		c.takeDamage(112333);
		for (int i = 0; i < 10; i++)
		{
			d.attack("C");
		}
		d = e;
		d.takeDamage(50);
	}
	return 0;
}