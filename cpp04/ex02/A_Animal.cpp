/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:39:39 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/16 07:29:32 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_Animal.hpp"

A_Animal::A_Animal()
{
	std::cout << "A_Animal is born" << std::endl;
	type = "{ Unidentify A_Animal Type }";
}

A_Animal::A_Animal(std::string input_type)
{
	std::cout << "A_Animal is born" << std::endl;
	type = input_type;
}

A_Animal::A_Animal(const A_Animal& object)
{
	std::cout << "A_Animal Cloning via Copy Constructor" << std::endl;
	type = object.type;
}

A_Animal&	A_Animal::operator=(const A_Animal& object)
{
	std::cout << "A_Animal Cloning via Copy Assignment" << std::endl;
	type = object.type;
	return *this;
}

std::string	A_Animal::getType()	const
{
	return type;
}

A_Animal::~A_Animal()
{
	std::cout << "A_Animal is die" << std::endl;
}