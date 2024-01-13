/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 05:29:47 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/14 05:36:50 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	WrongAnimal::type = "Not a Animal";
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << "WrongAnimal exist" << std::endl;
	WrongAnimal::type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal& object)
{
	std::cout << "WrongAnimal exist via Copy Constructor" << std::endl;
	WrongAnimal::type = object.type;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& object)
{
	std::cout << "WrongAnimal exist via Copy Assignment" << std::endl;
	WrongAnimal::type = object.type;
	return *this;
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
	std::cout << "WrongAnimal doesn't exist" << std::endl;
}