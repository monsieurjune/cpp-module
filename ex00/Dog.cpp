/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:39:51 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/14 05:35:44 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog is born" << std::endl;
}

Dog::Dog(const Dog& object) : Animal(object)
{
	std::cout << "Dog is cloning via Copy Constructor" << std::endl;
	Dog::type = object.type;
}

Dog&	Dog::operator=(const Dog& object)
{
	std::cout << "Dog is cloning via Copy Assignment" << std::endl;
	Dog::type = object.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog is die" << std::endl;
}

void	Dog::makeSound()	const
{
	std::cout << "Bark !!" << std::endl;
}