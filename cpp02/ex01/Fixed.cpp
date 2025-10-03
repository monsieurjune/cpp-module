/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:23:04 by tponutha          #+#    #+#             */
/*   Updated: 2023/11/13 14:32:22 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fraction = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	Fixed::fixed_point = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	Fixed::fixed_point = num << Fixed::fraction;
}

Fixed::Fixed(const float num)
{
	float	shift	= 1 << Fixed::fraction;
	float	invert;
	float	remider;

	std::cout << "Float constructor called" << std::endl;

	Fixed::fixed_point = num * shift;
	invert = Fixed::fixed_point / shift;
	remider = num - invert;

	if (remider < -0.001)
	{
		Fixed::fixed_point--;
	}
	if (remider > 0.0001)
	{
		Fixed::fixed_point++;
	}
}

Fixed::Fixed(const Fixed &object)
{
	std::cout << "Copy constructor called" << std::endl;
	Fixed::fixed_point = object.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits()	const
{
	std::cout << "getRawBits member function called" << std::endl;
	return fixed_point;
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	Fixed::fixed_point = raw;
}

int		Fixed::toInt()	const
{
	float	remider	= 0;
	float	exp		= 0.5;

	for (int i = Fixed::fraction - 1; i >= 0; i--)
	{
		if ((Fixed::fixed_point & (1<<i)) != 0)
		{
			remider += exp;
		}
		exp *= 0.5;
	}
	if (remider > 0.5)
	{
		return (Fixed::fixed_point >> Fixed::fraction) + 1;
	}
	return Fixed::fixed_point >> Fixed::fraction;
}

float	Fixed::toFloat()	const
{
	float	exp		= 0.5;
	float	decimal	= Fixed::fixed_point >> Fixed::fraction;
	
	for (int i = Fixed::fraction - 1; i >= 0; i--)
	{
		if ((Fixed::fixed_point & (1<<i)) != 0)
		{
			decimal += exp;
		}
		exp *= 0.5;
	}
	return decimal;
}

Fixed&	Fixed::operator=(const Fixed &object)
{	
	std::cout << "Copy assignment operator called" << std::endl;
	Fixed::fixed_point = object.getRawBits();
	return *this;
}

std::ostream&	operator<<(std::ostream &out, const Fixed &object)
{
	out << object.toFloat();
	return out;
}