/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:39:39 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/14 05:34:22 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal is born" << std::endl;
	Animal::type = "{ Unidentify Animal Type }";
}

Animal::Animal(std::string type)
{
	std::cout << "Animal is born" << std::endl;
	Animal::type = type;
}

Animal::Animal(const Animal& object)
{
	std::cout << "Animal Cloning via Copy Constructor" << std::endl;
	Animal::type = object.type;
}

Animal&	Animal::operator=(const Animal& object)
{
	std::cout << "Animal Cloning via Copy Assignment" << std::endl;
	Animal::type = object.type;
	return *this;
}

std::string	Animal::getType()	const
{
	return Animal::type;
}

void	Animal::makeSound()	const
{
	std::cout << "{ Unidentify Animal Sound }" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal is die" << std::endl;
}