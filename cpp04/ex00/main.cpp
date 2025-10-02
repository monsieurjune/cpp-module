/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:39:56 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/18 02:31:31 by tponutha         ###   ########.fr       */
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
	const Animal* i_clone1 = new Cat(*i);
	const Animal* j_clone1 = new Dog(*j);
	
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete i;
	delete j;

	std::cout << "\nClone Activities" << std::endl;
	i_clone1->makeSound();
	j_clone1->makeSound();
	
	delete i_clone1;
	delete j_clone1;

	std::cout << "\ntest wrong Animal" << std::endl;

	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* l = new WrongCat();
	const WrongAnimal* l_clone = new WrongCat(*l);

	std::cout << meta2->getType() << std::endl;
	std::cout << l->getType() << std::endl;

	l->makeSound();
	meta2->makeSound();

	delete l;
	delete meta2;

	std::cout << "\nClone Activities" << std::endl;
	l_clone->makeSound();

	delete l_clone;

	return 0;
}