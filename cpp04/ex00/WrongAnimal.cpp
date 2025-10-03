/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 05:29:47 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/16 07:30:53 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	WrongAnimal::type = "Not a Animal";
}

WrongAnimal::WrongAnimal(std::string input_type)
{
	std::cout << "WrongAnimal exist" << std::endl;
	type = input_type;
}

WrongAnimal::WrongAnimal(const WrongAnimal& object)
{
	std::cout << "WrongAnimal exist via Copy Constructor" << std::endl;
	type = object.type;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& object)
{
	std::cout << "WrongAnimal exist via Copy Assignment" << std::endl;
	type = object.type;
	return *this;
}

std::string	WrongAnimal::getType()	const
{
	return type;
}

void	WrongAnimal::makeSound()	const
{
	std::cout << "BRUH !!!!!" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal doesn't exist" << std::endl;
}