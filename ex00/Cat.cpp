/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:39:46 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/18 02:20:58 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat is born" << std::endl; 
}

Cat::Cat(const Cat& object) : Animal(object)
{
	std::cout << "Cat is cloning via Copy Constructor" << std::endl;
	type = object.type;
}

Cat::Cat(const Animal& object) : Animal(object)
{
	std::cout << type << " become Cat via Copy Constructor" << std::endl;
	type = "Cat";
}

Cat&	Cat::operator=(const Cat& object)
{
	std::cout << "Cat is cloning via Copy Assignment" << std::endl;
	type = object.type;
	return *this;
}

// Cat&	Cat::operator=(const Animal& object)
// {
// 	std::cout << type << " become Cat. via Copy Assignment" << std::endl;
// 	type = "Cat";
// 	return *this;
// }

Cat::~Cat()
{
	std::cout << "Cat is die" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow !!!" << std::endl;
}