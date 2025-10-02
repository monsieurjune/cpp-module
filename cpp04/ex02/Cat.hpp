/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 23:39:48 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/19 21:13:24 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "A_Animal.hpp"
# include "Brain.hpp"

class Cat : public A_Animal
{
	public:
		Cat();
		Cat(const Cat& object);
		~Cat();
		Cat&		operator=(const Cat& object);
		void		makeSound() const;
		void		setIdea(size_t i, std::string idea);
		std::string	getIdea(size_t i)	const;

	private:
		Brain*	brain_ptr;
};

#endif