/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:39:51 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/18 23:50:37 by tponutha         ###   ########.fr       */
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
	type = object.type;
}

Dog::Dog(const Animal& object) : Animal(object)
{
	std::cout << type << " become Dog via Copy Constructor" << std::endl;
	type = "Dog";
}

Dog&	Dog::operator=(const Dog& object)
{
	std::cout << "Dog is cloning via Copy Assignment" << std::endl;
	type = object.type;
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