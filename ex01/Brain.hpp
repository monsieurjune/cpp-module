/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 06:16:19 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/14 05:31:03 by tponutha         ###   ########.fr       */
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
		Brain&	operator=(const Brain& object);
	
	private:
		std::string ideas[100];
};

#endif