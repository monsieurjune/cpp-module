/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 02:49:06 by tponutha          #+#    #+#             */
/*   Updated: 2023/11/09 10:51:36 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	PhoneBook::index = 0;
}

// ADD

static bool	sb_input_phone_num(std::string &num)
{
	for (int i = 0; i < READ_NO; i++)
	{
		ft_prompt("Phone Number : ", num);
		if (num.empty())
			continue;
		if (!ft_is_number(num))
		{
			std::cout << "There is non-digit charactor(s) in Phone-Number" << std::endl;
		}
		else
			return true;
	}
	std::cout << "Wrong input " << READ_NO << " time already, run command again" << std::endl;
	return false;
}

static bool	sb_userinput(std::string prmpt, std::string &line)
{
	for (int i = 0; i < READ_NO; i++)
	{
		ft_prompt(prmpt, line);
		if (line.empty())
		{
			std::cout << "Empty line input !!!" << std::endl;
			continue;
		}
		if (!ft_is_alphabet(line))
		{
			std::cout << "There is non-alphabet charactor(s) in user's input" << std::endl;
		}
		else
			return true;
	}
	std::cout << "Wrong input " << READ_NO << " time already, run command again" << std::endl;
	return false;
}

void	PhoneBook::add()
{
	std::string		first;
	std::string		last;
	std::string		nick;
	std::string		num;
	std::string		secret;

	// Input
	if (!sb_userinput("First Name : ", first)) {return;}
	if (!sb_userinput("Last Name : ", last)) {return;}
	if (!sb_userinput("Nickname : ", nick)) {return;}
	if (!sb_input_phone_num(num)) {return;}
	if (!sb_userinput("Darkest Secret : ", secret)) {return;}

	// Initialize contact list
	PhoneBook::contact_list[PhoneBook::index].set_firstname(first);
	PhoneBook::contact_list[PhoneBook::index].set_lastname(last);
	PhoneBook::contact_list[PhoneBook::index].set_nickname(nick);
	PhoneBook::contact_list[PhoneBook::index].set_phonenum(num);
	PhoneBook::contact_list[PhoneBook::index].set_secret(secret);

	// Toggle index
	PhoneBook::index += 1;
	PhoneBook::index = PhoneBook::index >= 8 ? 0:PhoneBook::index;
}

// SEARCH

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

static bool	sb_check_index_bound(Contact *list, int n)
{
	if (n < 0 || n > 7)
	{
		std::cout << "Index is out of range" << std::endl;
		return false;
	}
	if (list[n].isempty())
	{
		std::cout << "Index is out of range" << std::endl;
		return false;
	}
	return true;
}

static bool	sb_input_index(int &n)
{
	std::string		input;

	for (int i = 0; i < READ_NO; i++)
	{
		ft_prompt("Index : ", input);
		if (input.empty())
		{
			std::cout << "Empty line input !!!" << std::endl;
			continue;
		}
		if (!ft_is_number(input))
		{
			std::cout << "There is non-digit charactor(s) in Index" << std::endl;
			continue;
		}
		if (!ft_convert_index(input, n))
		{
			std::cout << "Index is TOO LONG" << std::endl;
			continue;
		}
		else
			return true;
	}
	std::cout << "Wrong input " << READ_NO << " time already, run command again" << std::endl;
	return false;
}

void	PhoneBook::search()
{
	int	n;

	// Print table & choose index
	sb_display_table(PhoneBook::contact_list);

	// String to integer
	if (!sb_input_index(n)) {return;}
	n -= 1;
	if (!sb_check_index_bound(PhoneBook::contact_list, n)) {return;}

	// Display information
	std::cout << "First Name     : " << PhoneBook::contact_list[n].get_firstname(false) << std::endl;
	std::cout << "Last Name      : " << PhoneBook::contact_list[n].get_lastname(false) << std::endl;
	std::cout << "Nickname       : " << PhoneBook::contact_list[n].get_nickname(false) << std::endl;
	std::cout << "Phone Number   : " << PhoneBook::contact_list[n].get_phone_number() << std::endl;
	std::cout << "Darkest Secret : " << PhoneBook::contact_list[n].get_secret() << std::endl;
}

bool	PhoneBook::get_command(std::string cmd)
{
	if (cmd == "EXIT")
		return false;
	if (cmd == "ADD")
		PhoneBook::add();
	else if (cmd == "SEARCH")
		PhoneBook::search();
	else
	{
		std::cout << "-------------------------------------------------" << std::endl;
		std::cout << "WRONG OPTION (There is only 3 option)" << std::endl;
		std::cout << "ADD    : add people's information to phonebook" << std::endl;
		std::cout << "SEARCH : search people's information on phonebook" << std::endl;
		std::cout << "EXIT   : exit phonebook program" << std::endl;
		std::cout << "-------------------------------------------------" << std::endl;
	}
	return true;
}
