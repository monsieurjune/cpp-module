/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:39:39 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/13 07:23:03 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(std::string type)
{
	Animal::type = type;
	Animal::myBrain = new Brain;
}

Animal::Animal()
{
	Animal::type = "{ Unidentify Animal Type }";
}

std::string	Animal::getType()	const
{
	return Animal::type;
}

Animal::~Animal()
{
	delete Animal::myBrain;
}