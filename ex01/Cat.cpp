/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:39:46 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/19 00:17:57 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat is born" << std::endl; 
	brain_ptr = new Brain();
}

Cat::Cat(const Cat& object) : Animal(object)
{
	std::cout << "Cat is cloning via Copy Constructor" << std::endl;
	brain_ptr = new Brain(*object.brain_ptr);
}

Cat&	Cat::operator=(const Cat& object)
{
	std::cout << "Cat is cloning via Copy Assignment" << std::endl;
	type = object.type;
	*brain_ptr = *object.brain_ptr;
	return *this;
}

Cat::~Cat()
{
	delete brain_ptr;
	std::cout << "Cat is die" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow !!!" << std::endl;
}

std::string	Cat::getIdea(size_t i)	const
{
	return brain_ptr->getIdea(i);
}

void	Cat::setIdea(size_t i, std::string idea)
{
	brain_ptr->setIdea(i, idea);
}