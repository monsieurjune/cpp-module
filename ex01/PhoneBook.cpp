/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 02:49:06 by tponutha          #+#    #+#             */
/*   Updated: 2023/10/25 05:29:54 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static bool	sb_isn_number(std::string num)
{
	for (size_t	i = 0; i < num.length(); i++)
	{
		if (!isdigit(num[i]))
			return true;
	}
	return false;
}

bool	PhoneBook::add()
{
	std::string		first;
	std::string		last;
	std::string		nick;
	std::string		num;
	std::string		secret;

	// Input
	std::cout << "First Name : ";
	if (!std::getline(std::cin, first))
		return false;

	std::cout << "Last Name : ";
	if (!std::getline(std::cin, last))
		return false;

	std::cout << "Nickname : ";
	if (!std::getline(std::cin, nick))
		return false;

	std::cout << "Phone Number : ";
	if (!std::getline(std::cin, num))
		return false;

	std::cout << "Darkest Secret : ";
	if (!std::getline(std::cin, secret))
		return false;

	// Print if one of input isn't valid
	if (first.empty() || last.empty() || nick.empty() || num.empty() || secret.empty())
	{
		std::cout << "User didn't input some of information" << std::endl;
		return true;
	}
	if (sb_isn_number(num))
	{
		std::cout << "Input Phone number isn't valid number" << std::endl;
		return true;
	}

	// Initialize contact list
	PhoneBook::contact_list[PhoneBook::index].set_firstname(first);
	PhoneBook::contact_list[PhoneBook::index].set_lastname(last);
	PhoneBook::contact_list[PhoneBook::index].set_nickname(nick);
	PhoneBook::contact_list[PhoneBook::index].set_phonenum(num);
	PhoneBook::contact_list[PhoneBook::index].set_secret(secret);

	// Toggle index
	PhoneBook::index += 1;
	if (PhoneBook::index >= 8)
		PhoneBook::index = 0;
	return true;
}

bool	PhoneBook::search()
{
	std::string			input;
	std::stringstream	tmp;
	int					n = 0;

	// Print table
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "| N | First Name |  Last Name |   Nickname |" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (PhoneBook::contact_list[i].isempty())
			break;
		std::cout << "| " << i+1 << " | ";
		std::cout << PhoneBook::contact_list[i].get_firstname(true) << " | ";
		std::cout << PhoneBook::contact_list[i].get_lastname(true) << " | ";
		std::cout << PhoneBook::contact_list[i].get_nickname(true) << " |" << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
	}

	// Choose index
	std::cout << "Index : ";
	if (!std::getline(std::cin, input))
		return false;
	if (input.length() != 1)
	{
		std::cout << "Input too long" << std::endl;
		return true;
	}
	if (!isdigit(input[0]))
	{
		std::cout << "There is non-number charactor(s) here" << std::endl;
		return true;
	}

	// String to integer
	tmp << input;
	tmp >> n;
	n--;
	if (n >= 8)
	{
		std::cout << "Out of range" << std::endl;
		return true;
	}
	if (PhoneBook::contact_list[n].isempty())
	{
		std::cout << "Out of range" << std::endl;
		return true;
	}

	// Display information
	std::cout << "First Name     : " << PhoneBook::contact_list[n].get_firstname(false) << std::endl;
	std::cout << "Last Name      : " << PhoneBook::contact_list[n].get_lastname(false) << std::endl;
	std::cout << "Nickname       : " << PhoneBook::contact_list[n].get_nickname(false) << std::endl;
	std::cout << "Phone Number   : " << PhoneBook::contact_list[n].get_phone_number() << std::endl;
	std::cout << "Darkest Secret : " << PhoneBook::contact_list[n].get_secret() << std::endl;
	return true;
}

bool	PhoneBook::get_command(std::string cmd)
{
	if (cmd == "EXIT")
		return false;
	if (cmd == "ADD")
		return PhoneBook::add();
	else if (cmd == "SEARCH")
		return PhoneBook::search();
	return true;
}

PhoneBook::PhoneBook()
{
	PhoneBook::index = 0;
}