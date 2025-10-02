/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:39:51 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/19 00:16:30 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog is born" << std::endl;
	brain_ptr = new Brain();
}

Dog::Dog(const Dog& object) : Animal(object)
{
	std::cout << "Dog is cloning via Copy Constructor" << std::endl;
	brain_ptr = new Brain(*object.brain_ptr);
}

Dog&	Dog::operator=(const Dog& object)
{
	std::cout << "Dog is cloning via Copy Assignment" << std::endl;
	type = object.type;
	*brain_ptr = *object.brain_ptr;
	return *this;
}

Dog::~Dog()
{
	delete brain_ptr;
	std::cout << "Dog is die" << std::endl;
}

void	Dog::makeSound()	const
{
	std::cout << "Bark !!" << std::endl;
}

std::string	Dog::getIdea(size_t i)	const
{
	return brain_ptr->getIdea(i);
}

void	Dog::setIdea(size_t i, std::string idea)
{
	brain_ptr->setIdea(i, idea);
}