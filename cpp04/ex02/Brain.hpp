/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 06:16:19 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/19 00:13:02 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain& object);
		~Brain();
		Brain&		operator=(const Brain& object);
		std::string	getIdea(size_t i)	const;
		void		setIdea(size_t i, std::string idea);
	
	private:
		std::string ideas[100];
};

#endif