/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:39:56 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/13 14:14:24 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	int		amout	= 101;
	A_Animal	**herd	= NULL;

	try
	{
		herd = new A_Animal* [amout]();
		for (int i = 0; i < amout; i++)
		{
			herd[i] = NULL;
		}
		for (int i = 0; i < amout / 2; i++)
		{
			herd[i] = new Dog();
		}
		for (int i = amout / 2; i < amout; i++)
		{
			herd[i] = new Cat();
		}
		for (int i = 0; i < amout; i++)
		{
			herd[i]->makeSound();
		}
	}
	catch (std::bad_alloc &alloc_error) {}
	
	for (int i = 0; i < amout; i++)
		{
			delete herd[i];
		}
		delete [] herd;
	return 0;
}