/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 01:08:49 by tponutha          #+#    #+#             */
/*   Updated: 2023/10/28 18:30:25 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::set_firstname(std::string first)
{
	Contact::firstname = first;
}

void	Contact::set_lastname(std::string last)
{
	Contact::lastname = last;
}

void	Contact::set_nickname(std::string nick)
{
	Contact::nickname = nick;
}

void	Contact::set_phonenum(std::string num)
{
	Contact::phone_number = num;
}

void	Contact::set_secret(std::string secret)
{
	Contact::secret = secret;
}

bool	Contact::isempty()
{
	bool	isEmpty;

	isEmpty = Contact::firstname.empty();
	isEmpty |= Contact::lastname.empty();
	isEmpty |= Contact::nickname.empty();
	isEmpty |= Contact::phone_number.empty();
	isEmpty |= Contact::secret.empty();
	return isEmpty;
}

static std::string	sb_handle_output(std::string str, bool isTrunc)
{
	std::string		res = "";
	size_t			len = str.length();

	if (!isTrunc || len == 10){ return str; }
	if (len < 10)
	{
		res.assign(10 - len, ' ');
		res.append(str);
	}
	else
	{
		res = str.substr(0, 9);
		res.append(".");
	}
	return res;
}

std::string	Contact::get_firstname(bool isTrunc)
{
	return sb_handle_output(Contact::firstname, isTrunc);
}

std::string	Contact::get_lastname(bool isTrunc)
{
	return sb_handle_output(Contact::lastname, isTrunc);
}

std::string	Contact::get_nickname(bool isTrunc)
{
	return sb_handle_output(Contact::nickname, isTrunc);
}

std::string	Contact::get_phone_number()
{
	return Contact::phone_number;
}

std::string	Contact::get_secret()
{
	return Contact::secret;
}

Contact::Contact()
{
	Contact::firstname = "";
	Contact::lastname = "";
	Contact::nickname = "";
	Contact::phone_number = "";
	Contact::secret = "";
}