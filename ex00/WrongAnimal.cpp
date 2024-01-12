/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 05:29:47 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/13 06:01:36 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	WrongAnimal::type = "Not a Animal";
}

WrongAnimal::WrongAnimal(std::string type)
{
	WrongAnimal::type = type;
}

std::string	WrongAnimal::getType()	const
{
	return WrongAnimal::type;
}

void	WrongAnimal::makeSound()	const
{
	std::cout << "BRUH !!!!!" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	
}