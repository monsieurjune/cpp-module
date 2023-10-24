/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 00:07:00 by tponutha          #+#    #+#             */
/*   Updated: 2023/10/25 04:47:40 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	bool			isRun;
	PhoneBook		yellow;
	std::string		cmd;

	do
	{
		std::cout << "PHONEBOOK> ";
		if (!std::getline(std::cin, cmd))
			return (0);
		isRun = yellow.get_command(cmd);
	} while (isRun);
	return (0);
}