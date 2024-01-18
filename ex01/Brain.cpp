/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 06:16:14 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/19 00:15:42 by tponutha         ###   ########.fr       */
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

std::string	Brain::getIdea(size_t i)	const
{
	if (i >= 100)
		return "{Out of Ideas}";
	return ideas[i];
}

void	Brain::setIdea(size_t i, std::string idea)
{
	if (i >= 100)
		return;
	ideas[i] = idea;
}