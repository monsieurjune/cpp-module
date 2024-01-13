/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:39:56 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/14 05:18:11 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal* i_clone = new Animal(*i);
	
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;

	i_clone->makeSound();
	delete i_clone;

	std::cout << "test wrong Animal" << std::endl;

	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongCat* l = new WrongCat();
	std::cout << meta2->getType() << std::endl;
	std::cout << l->getType() << std::endl;

	l->makeSound();
	meta2->makeSound();

	delete l;
	delete meta2;

	return 0;
}