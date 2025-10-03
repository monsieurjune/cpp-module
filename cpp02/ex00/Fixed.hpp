/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:23:07 by tponutha          #+#    #+#             */
/*   Updated: 2023/11/13 00:16:57 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &object);
		Fixed&	operator=(const Fixed &object);
		int		getRawBits() const;
		void	setRawBits(const int raw);
	
	private:
		int					fixed_point;
		static const int	fraction;
};

#endif