/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 03:19:00 by tponutha          #+#    #+#             */
/*   Updated: 2023/11/09 04:08:41 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static bool	prompt(std::string prompt, std::string &line)
{
	std::cout << prompt;
	return !std::getline(std::cin, line);
}

int	main()
{
	Harl			run;
	std::string		line;

	while (!prompt("Harl> ", line))
	{
		run.complain(line);
	}
	return (0);
}