/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:39:54 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/18 02:08:39 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& object);
		Dog(const Animal& object);
		~Dog();
		Dog&	operator=(const Dog& object);
		void	makeSound()	const;
};

#endif