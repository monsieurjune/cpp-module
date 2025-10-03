/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 03:19:04 by tponutha          #+#    #+#             */
/*   Updated: 2023/11/12 16:57:25 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug()
{
	std::cout <<  "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info()
{
	std::cout <<  "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error()
{
	std::cout <<  "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	Harl			tmp;
	cmd_set			set[]	= {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string		cmds[]	= {"debug", "info", "warning", "error"};
	size_t			size	= 4;

	for (size_t i = 0; i < size; i++)
	{
		if (cmds[i] == level)
		{
			(tmp.*set[i])();
		}
	}
}

static void	sb_print_header(std::string level)
{
	for (size_t i = 0; i < level.length(); i++)
	{
		level[i] = toupper(level[i]);
	}
	std::cout << "[ " << level << " ]" << std::endl;
}

void	Harl::filter(std::string level)
{
	std::string		cmds[]	= {"debug", "info", "warning", "error"};
	size_t			size	= 4;

	for (size_t i = 0; i < size; i++)
	{
		if (cmds[i] == level)
		{
			for (size_t j = i; j < size; j++)
			{
				sb_print_header(cmds[j]);
				Harl::complain(cmds[j]);
				std::cout << std::endl;
			}
			return;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}