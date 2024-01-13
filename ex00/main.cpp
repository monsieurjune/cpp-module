/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:13:22 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/13 16:20:29 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	a("A");
	ClapTrap	a_clone(a);

	a.takeDamage(10);
	a.beRepaired(5);
	a.attack("B");

	a_clone = a;
	for (int i = 0; i < 10; i++)
	{
		a.attack("B");
		a_clone.takeDamage(1);
	}
	return 0;
}