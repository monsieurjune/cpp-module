/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:39:51 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/13 05:38:15 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog is born" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog is die" << std::endl;
}

void	Dog::makeSound()	const
{
	std::cout << "Bark !!" << std::endl;
}