/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 00:07:00 by tponutha          #+#    #+#             */
/*   Updated: 2023/11/09 10:47:50 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void	sb_tutorial_popup()
{
	std::cout << "Welocom to PhoneBook (There is 3 option)" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "ADD    : add people's information to phonebook" << std::endl;
	std::cout << "SEARCH : search people's information on phonebook" << std::endl;
	std::cout << "EXIT   : exit phonebook program" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
}

int	main()
{
	bool			isRun;
	PhoneBook		yellow;
	std::string		cmd;

	sb_tutorial_popup();
	try
	{
		do
		{
			ft_prompt("PHONEBOOK> ", cmd);
			isRun = yellow.get_command(cmd);
		}
		while (isRun);
		std::cout << "EXIT COMMAND IS ACTIVATED, EXIT PROGRAM" << std::endl;
	}
	catch (std::istream::failure &cout_err)
	{
		std::cout << "\nCtrl-D is Activated, Exit Program" << std::endl;
	}
	return (0);
}