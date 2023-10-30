/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 02:49:06 by tponutha          #+#    #+#             */
/*   Updated: 2023/10/31 05:25:29 by tponutha         ###   ########.fr       */
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

bool	ft_prompt(std::string prmpt, std::string &line)
{
	std::cout << prmpt;
	return !std::getline(std::cin, line);
}

bool	PhoneBook::add()
{
	std::string		first;
	std::string		last;
	std::string		nick;
	std::string		num;
	std::string		secret;

	// Input
	RETURN_GETLINE_IF_EOF(ft_prompt("First Name : ", first))
	RETURN_GETLINE_IF_EOF(ft_prompt("Last Name : ", last))
	RETURN_GETLINE_IF_EOF(ft_prompt("Nickname : ", nick))
	RETURN_GETLINE_IF_EOF(ft_prompt("Phone Number : ", num));
	RETURN_GETLINE_IF_EOF(ft_prompt("Darkest Secret : ", secret));

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
	PhoneBook::index = PhoneBook::index >= 8 ? 0:PhoneBook::index;
	return true;
}

static void	sb_display_table(Contact *contact_list)
{
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "| N | First Name |  Last Name |   Nickname |" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (contact_list[i].isempty())
			break;
		std::cout << "| " << i+1 << " | ";
		std::cout << contact_list[i].get_firstname(true) << " | ";
		std::cout << contact_list[i].get_lastname(true) << " | ";
		std::cout << contact_list[i].get_nickname(true) << " |" << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
	}
}

static int	sb_is_index_correct(std::string num, Contact *contact_list)
{
	std::stringstream	tmp;
	int					n;
	
	for (size_t i = 0; i < num.length(); i++)
	{
		if (!isdigit(num[i]))
		{
			std::cout << "There is non-number charactor in index input" << std::endl;
			return -1;
		}
	}
	tmp << num;
	tmp >> n;
	if (n > 8 || n < 1)
	{
		std::cout << "Index is out of contact list's bound" << std::endl;
		return -1;
	}
	n--;
	if (contact_list[n].isempty())
	{
		std::cout << "This Index (" << n + 1 << ") is empty" << std::endl;
		return -1;
	}
	return n - 1;
}

bool	PhoneBook::search()
{
	std::string			input;
	int					n;

	// Print table & choose index
	sb_display_table(PhoneBook::contact_list);
	RETURN_GETLINE_IF_EOF(ft_prompt("Index : ", input))

	// String to integer
	n = sb_is_index_correct(input, PhoneBook::contact_list);
	if (n < 0)
		return true;

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
	else
	{
		std::cout << "WRONG OPTION (There is only 3 option)" << std::endl;
		std::cout << "ADD    : add people's information to phonebook" << std::endl;
		std::cout << "SEARCH : search people's information on phonebook" << std::endl;
		std::cout << "EXIT   : exit phonebook program" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
	}
	return true;
}

PhoneBook::PhoneBook()
{
	PhoneBook::index = 0;
}