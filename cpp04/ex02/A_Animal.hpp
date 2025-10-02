/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:39:42 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/19 21:12:29 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>

class A_Animal
{
	public:
		A_Animal();
		A_Animal(const A_Animal& object);
		A_Animal(std::string input_type);
		virtual	~A_Animal();
		A_Animal&				operator=(const A_Animal& object);
		std::string			getType()	const;
		virtual void		makeSound()	const = 0;

	protected:
		std::string	type;
};

#endif