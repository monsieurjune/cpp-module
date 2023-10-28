/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 02:49:10 by tponutha          #+#    #+#             */
/*   Updated: 2023/10/28 20:33:32 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <sstream>
# include "Contact.hpp"

#ifndef RETURN_GETLINE_IF_EOF
# define RETURN_GETLINE_IF_EOF(GL) if (GL) { return false; }
#endif

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

bool	ft_prompt(std::string prmpt, std::string &line);

#endif