/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 00:07:00 by tponutha          #+#    #+#             */
/*   Updated: 2023/10/31 05:12:08 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	bool			isRun;
	size_t			first;
	size_t			last;
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
		first = cmd.find_first_not_of(' ');
		last = cmd.find_last_not_of(' ');
		isRun = yellow.get_command(cmd.substr(first, last - first + 1));
	} while (isRun);
	return (0);
}