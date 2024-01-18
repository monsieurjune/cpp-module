/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:39:42 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/18 22:53:55 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal& object);
		Animal(std::string input_type);
		virtual	~Animal();
		Animal&				operator=(const Animal& object);
		std::string			getType()	const;
		virtual void		makeSound()	const;
		virtual void		setIdea(size_t i, std::string idea) = 0;
		virtual std::string	getIdea(size_t i)	const = 0;

	protected:
		std::string	type;
};

#endif