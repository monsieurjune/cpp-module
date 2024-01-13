/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:39:46 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/14 05:12:30 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat is born" << std::endl; 
}

Cat::Cat(const Cat& object) : Animal(object)
{
	Cat::type = object.type;
}

Cat&	Cat::operator=(const Cat& object)
{
	Cat::type = object.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat is die" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow !!!" << std::endl;
}