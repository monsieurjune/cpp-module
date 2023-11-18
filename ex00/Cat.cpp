/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:39:46 by tponutha          #+#    #+#             */
/*   Updated: 2023/11/14 00:23:59 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("cat")
{
	std::cout << "Cat is born" << std::endl; 
}

Cat::~Cat()
{
	std::cout << "Cat is die" << std::endl;
}

void	Cat::makeSound()
{
	std::cout << "Meow !!!" << std::endl;
}