/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:23:07 by tponutha          #+#    #+#             */
/*   Updated: 2023/11/13 15:48:05 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &object);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(const int raw);
		float	toFloat() const;
		int		toInt() const;

		Fixed&	operator=(const Fixed &object);

		bool	operator==(const Fixed &b);
		bool	operator!=(const Fixed &b);
		bool	operator<(const Fixed &b);
		bool	operator<=(const Fixed &b);
		bool	operator>(const Fixed &b);
		bool	operator>=(const Fixed &b);

		Fixed	operator+(const Fixed &b);
		Fixed	operator-(const Fixed &b);
		Fixed	operator*(const Fixed &b);
		Fixed	operator/(const Fixed &b);

		Fixed&	operator++();
		Fixed&	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);

		static Fixed&		min(Fixed &a, Fixed &b);
		const static Fixed&	min(const Fixed &a, const Fixed &b);
		static Fixed&		max(Fixed &a, Fixed &b);
		const static Fixed&	max(const Fixed &a, const Fixed &b);
	
	private:
		int					fixed_point;
		static const int	fraction;
};

std::ostream&	operator<<(std::ostream &out, const Fixed &object);

#endif