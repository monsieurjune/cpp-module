/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:28:24 by tponutha          #+#    #+#             */
/*   Updated: 2023/10/25 15:09:29 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie*	horde;

	try
	{
		horde = new Zombie[N];
		for (int i = 0; i < N; i++)
		{
			horde[i].edit_name(name);
		}
		return horde;
	}
	catch (std::bad_alloc &e)
	{
		return NULL;
	}
}