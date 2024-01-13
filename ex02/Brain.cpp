/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 06:16:14 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/13 06:41:21 by tponutha         ###   ########.fr       */
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

Brain::~Brain()
{
	std::cout << "Brain died" << std::endl;
}