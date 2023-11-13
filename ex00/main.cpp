/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:13:22 by tponutha          #+#    #+#             */
/*   Updated: 2023/11/13 18:15:38 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	a("A");

	a.takeDamage(10);
	a.beRepaired(5);
	a.attack("B");
	for (int i = 0; i < 10; i++)
	{
		a.attack("B");
	}
	return 0;
}