/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:59:00 by tponutha          #+#    #+#             */
/*   Updated: 2023/10/25 14:26:01 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	Zombie::name = name;
}

Zombie::~Zombie()
{
	std::cout << Zombie::name << " is die" << std::endl;
}

void	Zombie::announce()
{
	std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}