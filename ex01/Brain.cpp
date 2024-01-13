/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 06:16:14 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/14 05:44:19 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
	{
		Brain::ideas[i] = "";
	}
	std::cout << "Creating a Brain" << std::endl;
}

Brain::Brain(const Brain& object)
{
	for (int i = 0; i < 100; i++)
	{
		Brain::ideas[i] = object.ideas[i];
	}
	std::cout << "Copying a Brain via Copy Constructor" << std::endl;
}

Brain&	Brain::operator=(const Brain& object)
{
	for (int i = 0; i < 100; i++)
	{
		Brain::ideas[i] = object.ideas[i];
	}
	std::cout << "Copying a Brain via Copy Assignment" << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain died" << std::endl;
}