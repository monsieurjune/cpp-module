/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:35:24 by tponutha          #+#    #+#             */
/*   Updated: 2023/10/27 03:29:19 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"


void	HumanA::attack()
{
	std::cout << HumanA::name << " attacks with their " << HumanA::rwpon << std::endl;
}

HumanA::HumanA(std::string name, Weapon &etc) : rwpon(etc.getType())
{
	HumanA::name = name;
}