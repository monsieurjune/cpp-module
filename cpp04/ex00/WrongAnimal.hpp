/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 05:29:43 by tponutha          #+#    #+#             */
/*   Updated: 2024/01/16 07:30:30 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& object);
		WrongAnimal(std::string input_type);
		virtual	~WrongAnimal();
		WrongAnimal&	operator=(const WrongAnimal& object);
		std::string		getType()	const;
		virtual void	makeSound()	const;

	protected:
		std::string	type;
};

#endif