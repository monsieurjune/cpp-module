/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:39:42 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/13 14:12:28 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include "Brain.hpp"

class A_Animal
{
	public:
		A_Animal();
		A_Animal(std::string type);
		virtual	~A_Animal();
		std::string		getType()	const;
		virtual void	makeSound()	const = 0;

	protected:
		std::string	type;
		Brain*		myBrain;
};

#endif