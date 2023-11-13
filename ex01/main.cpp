/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:13:22 by tponutha          #+#    #+#             */
/*   Updated: 2023/11/13 20:07:35 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
	return 0;
}