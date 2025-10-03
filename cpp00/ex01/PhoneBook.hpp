/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 02:49:10 by tponutha          #+#    #+#             */
/*   Updated: 2023/11/09 01:55:58 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "utils.hpp"
# include "Contact.hpp"

#ifndef RETURN_GETLINE_IF_EOF
# define RETURN_GETLINE_IF_EOF(GL) if (GL) { return false; }
#endif

class PhoneBook
{
	private:
		Contact		contact_list[8];
		int			index;
		void		add();
		void		search();

	public:
		PhoneBook();
		bool		get_command(std::string cmd);
};

#endif