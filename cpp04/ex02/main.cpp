/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:39:56 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/19 21:16:15 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

static const A_Animal*	clone_exist_A_Animal(const A_Animal* object)
{
	if (object->getType() == "Cat")
	{
		return new Cat(*(Cat *)object);
	}
	if (object->getType() == "Dog")
	{
		return new Dog(*(Dog *)object);
	}
	return NULL;
}

static void	setIdea(const A_Animal* object, size_t i, std::string idea)
{
	if (object->getType() == "Cat")
	{
		(*(Cat *)object).setIdea(i, idea);
	}
	if (object->getType() == "Dog")
	{
		(*(Dog *)object).setIdea(i, idea);
	}
}

static std::string	getIdea(const A_Animal* object, size_t i)
{
	if (object->getType() == "Cat")
	{
		return (*(Cat *)object).getIdea(i);
	}
	if (object->getType() == "Dog")
	{
		return (*(Dog *)object).getIdea(i);
	}
	return "{This kind of A_Animal doesn't has brain}";
}

int main()
{
	size_t	amout = 5;
	A_Animal** herd = new A_Animal*[amout]();

	// Create herd
	for (size_t i = 0; i < amout / 2 + amout % 2; i++)
	{
		herd[i] = new Dog();
	}
	for (size_t i = amout / 2 + amout % 2; i < amout; i++)
	{
		herd[i] = new Cat();
	}
	std::cout << herd[0]->getType() << std::endl;
	std::cout << "\n--------------------------------------------" << std::endl;

	// Set specific idea
	setIdea(herd[0], 50, "Eat Something");
	setIdea(herd[0], 51, "Drink Something");
	setIdea(herd[amout - 1], 20, "Buying stock");
	setIdea(herd[amout - 1], 21, "Buying currency");

	// Clone specific
	const A_Animal* test1 = clone_exist_A_Animal(herd[0]);
	const A_Animal* test2 = clone_exist_A_Animal(herd[amout - 1]);

	// Set specific idea to clone for checking deep copy1
	setIdea(test1, 50, "Driving a Car");
	setIdea(test1, 51, "Sleeping");
	setIdea(test2, 20, "Go to School");
	setIdea(test2, 21, "Go to Pub");

	// check deep copy1
	std::cout << "\n--------------------------------------------" << std::endl;
	std::cout << "Original Idea : " << getIdea(herd[0], 50) << "\n"
				<< "Clone Idea : " << getIdea(test1, 50)  << std::endl;
	std::cout << "Original Idea : " << getIdea(herd[0], 51) << "\n"
				<< "Clone Idea : " << getIdea(test1, 51)  << std::endl;
	std::cout << "Original Idea : " << getIdea(herd[amout - 1], 20) << "\n"
				<< "Clone Idea : " << getIdea(test2, 20)  << std::endl;
	std::cout << "Original Idea : " << getIdea(herd[amout - 1], 21) << "\n"
				<< "Clone Idea : " << getIdea(test2, 21)  << std::endl;

	// Delete herd
	std::cout << "\n--------------------------------------------" << std::endl;
	for (size_t i = 0; i < amout; i++)
	{
		delete herd[i];
	}
	delete [] herd;

	// Check deep copy2
	std::cout << "\n--------------------------------------------" << std::endl;

	std::cout << test1->getType() << std::endl;
	std::cout << test2->getType() << std::endl;
	std::cout << "Clone Idea : " << getIdea(test1, 50) << std::endl;
	std::cout << "Clone Idea : " << getIdea(test1, 51) << std::endl;
	std::cout << "Clone Idea : " << getIdea(test2, 20) << std::endl;
	std::cout << "Clone Idea : " << getIdea(test2, 21) << std::endl;
	test1->makeSound();
	test2->makeSound();

	// Delete clone
	delete test1;
	delete test2;
	return 0;
}