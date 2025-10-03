/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:36:10 by tponutha          #+#    #+#             */
/*   Updated: 2023/11/09 10:40:59 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void	ft_prompt(std::string prmpt, std::string &line)
{
	size_t		first;
	size_t		last;

	std::cout << prmpt;
	if (!std::getline(std::cin, line))
		throw std::istream::failure ("STDOUT-EOF");
	if (line.empty())
		return;
	first = line.find_first_not_of(' ');
	last = line.find_last_not_of(' ');
	if (first > line.length())
	{
		line = "";
		return;
	}
	line = line.substr(first, last - first + 1);
}

bool	ft_is_alphabet(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isalpha(str[i]))
			return false;
	}
	return true;
}

bool	ft_is_number(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

bool	ft_convert_index(std::string str, int &num)
{
	std::stringstream	tmp;
	size_t				first;

	first = str.find_first_not_of('0');
	if (first > str.length())
	{
		num = 0;
		return true;
	}
	str = str.substr(first, str.length() - first);
	if (str.length() > 1)
		return false;
	tmp << str;
	tmp >> num;
	return true;
}