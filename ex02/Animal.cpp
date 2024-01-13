/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:39:39 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/13 14:12:28 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

A_Animal::A_Animal(std::string type)
{
	A_Animal::type = type;
	A_Animal::myBrain = new Brain;
}

A_Animal::A_Animal()
{
	A_Animal::type = "{ Unidentify Animal Type }";
}

std::string	A_Animal::getType()	const
{
	return A_Animal::type;
}

A_Animal::~A_Animal()
{
	delete A_Animal::myBrain;
}