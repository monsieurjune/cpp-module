/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 02:49:10 by tponutha          #+#    #+#             */
/*   Updated: 2023/10/25 05:00:11 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <sstream>
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact		contact_list[8];
		int			index;
		bool		add();
		bool		search();

	public:
		PhoneBook();
		bool		get_command(std::string cmd);
};

#endif