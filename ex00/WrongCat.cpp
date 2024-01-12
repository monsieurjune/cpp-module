/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 05:29:34 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/13 06:03:50 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat's dad going to buy a milk" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat : X(" << std::endl;
}

void	WrongCat::makeSound()	const
{
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Won’t you miss the nights we drifted afar" << std::endl;
	std::cout << "And knew we would find a place in the stars for two" << std::endl;
	std::cout << "Taking you to dance in the sky" << std::endl;
	std::cout << "The nights you would be beside me" << std::endl;
	std::cout << "Your lips to mine" << std::endl;
	std::cout << "Nothing could compare" << std::endl;
	std::cout << "But every star’s light" << std::endl;
	std::cout << "Waits for you in the dark tonight" << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}
