/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 00:07:00 by tponutha          #+#    #+#             */
/*   Updated: 2023/10/28 20:33:50 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	bool			isRun;
	PhoneBook		yellow;
	std::string		cmd;

	std::cout << "Welocom to PhoneBook (There is 3 option)" << std::endl;
	std::cout << "ADD    : add people's information to phonebook" << std::endl;
	std::cout << "SEARCH : search people's information on phonebook" << std::endl;
	std::cout << "EXIT   : exit phonebook program" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	do
	{
		if (ft_prompt("PHONEBOOK> ", cmd))
		{
			return (0);
		}
		isRun = yellow.get_command(cmd);
	} while (isRun);
	return (0);
}