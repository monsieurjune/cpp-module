/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:39:46 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/13 14:12:41 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : A_Animal("Cat")
{
	std::cout << "Cat is born" << std::endl; 
}

Cat::~Cat()
{
	std::cout << "Cat is die" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow !!!" << std::endl;
}