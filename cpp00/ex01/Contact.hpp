/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:59:42 by tponutha          #+#    #+#             */
/*   Updated: 2023/10/25 04:05:13 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class Contact
{
	private:
		std::string		firstname;
		std::string		lastname;
		std::string		nickname;
		std::string		phone_number;
		std::string		secret;

	public:
		Contact();
		bool			isempty();
		void			set_firstname(std::string first);
		void			set_lastname(std::string last);
		void			set_nickname(std::string nick);
		void			set_phonenum(std::string num);
		void			set_secret(std::string secret);
		std::string		get_firstname(bool isTrunc);
		std::string		get_lastname(bool isTrunc);
		std::string		get_nickname(bool isTrunc);
		std::string		get_phone_number();
		std::string		get_secret();
};

#endif