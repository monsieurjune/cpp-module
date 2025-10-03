/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 03:19:00 by tponutha          #+#    #+#             */
/*   Updated: 2023/11/12 16:50:59 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static bool	prompt(std::string prompt, std::string &line)
{
	std::cout << prompt;
	return !std::getline(std::cin, line);
}

static void tutorial()
{
	std::cout << "Welcome to Harl 2.0 here 4 level of command" << std::endl;
	std::cout << "- level1 : debug" << std::endl;
	std::cout << "- level2 : info" << std::endl;
	std::cout << "- level3 : warning" << std::endl;
	std::cout << "- level4 : error" << std::endl;
}

int	main()
{
	Harl			run;
	size_t			first;
	size_t			last;
	std::string		line;

	tutorial();
	while (!prompt("Harl> ", line))
	{
		first = line.find_first_not_of(' ');
		last = line.find_last_not_of(' ');
		if (first <= line.length())
		{
			line = line.substr(first, last - first + 1);
		}
		else
		{
			line = "";
		}
		run.complain(line);
	}
	return (0);
}