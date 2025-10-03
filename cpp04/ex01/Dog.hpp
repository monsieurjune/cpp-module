/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:39:54 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/18 23:08:34 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& object);
		~Dog();
		Dog&		operator=(const Dog& object);
		void		makeSound()	const;
		void		setIdea(size_t i, std::string idea);
		std::string	getIdea(size_t i)	const;

	private:
		Brain*	brain_ptr;
};

#endif