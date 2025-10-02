/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:13:22 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/13 17:17:56 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	a("A");
	ClapTrap	a_clone(a);

	a_clone = a;
	a.takeDamage(100000);
	a.beRepaired(5);
	a.attack("B");


	for (int i = 0; i < 10; i++)
	{
		a.attack("B");
		a_clone.takeDamage(1);
	}
	return 0;
}