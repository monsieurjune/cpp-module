/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:39:42 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/14 05:54:04 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include "Brain.hpp"

class Animal
{
	public:
		Animal();
		Animal(const Animal& object);
		Animal(std::string type);
		virtual	~Animal();
		Animal&			operator=(const Animal& object);
		std::string		getType()	const;
		virtual void	makeSound()	const = 0;

	protected:
		std::string	type;
		Brain*		myBrain;
};

#endif