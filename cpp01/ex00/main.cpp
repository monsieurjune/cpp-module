/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:58:41 by tponutha          #+#    #+#             */
/*   Updated: 2023/10/25 14:24:39 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	std::string	name1 = "No1";
	std::string	name2 = "No2";
	std::string	name3 = "No3";
	std::string	name4 = "No4";
	std::string	name5 = "No5";
	std::string	name6 = "No6";
	std::string	name7 = "No7";

	Zombie	*zom1 = newZombie(name1);
	Zombie	*zom2 = newZombie(name2);
	Zombie	*zom3 = newZombie(name3);

	zom3->announce();
	randomChump(name4);
	randomChump(name5);
	zom2->announce();
	zom1->announce();
	randomChump(name6);
	randomChump(name7);

	delete zom2;
	zom1->announce();
	delete zom3;
	delete zom1;
	return 0;
}