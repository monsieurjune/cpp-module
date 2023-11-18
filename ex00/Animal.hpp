/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:39:42 by tponutha          #+#    #+#             */
/*   Updated: 2023/11/14 18:17:40 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
	public:
		Animal();
		Animal(std::string type);
		virtual	~Animal();
		std::string&	getType()	const;
		virtual void	makeSound()	const;

	protected:
		std::string	type;
};

#endif