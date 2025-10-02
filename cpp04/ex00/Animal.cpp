/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:39:39 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/16 07:29:32 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal is born" << std::endl;
	type = "{ Unidentify Animal Type }";
}

Animal::Animal(std::string input_type)
{
	std::cout << "Animal is born" << std::endl;
	type = input_type;
}

Animal::Animal(const Animal& object)
{
	std::cout << "Animal Cloning via Copy Constructor" << std::endl;
	type = object.type;
}

Animal&	Animal::operator=(const Animal& object)
{
	std::cout << "Animal Cloning via Copy Assignment" << std::endl;
	type = object.type;
	return *this;
}

std::string	Animal::getType()	const
{
	return type;
}

void	Animal::makeSound()	const
{
	std::cout << "{ Unidentify Animal Sound }" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal is die" << std::endl;
}