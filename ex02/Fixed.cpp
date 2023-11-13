/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:23:04 by tponutha          #+#    #+#             */
/*   Updated: 2023/11/13 16:37:52 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fraction = 8;

// Constructor

Fixed::Fixed()
{
	Fixed::fixed_point = 0;
}

Fixed::Fixed(const int num)
{
	Fixed::fixed_point = num << Fixed::fraction;
}

Fixed::Fixed(const float num)
{
	float	shift	= 1 << Fixed::fraction;
	float	invert;
	float	remider;

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
	Fixed::fixed_point = object.getRawBits();
}

// Deconstructor

Fixed::~Fixed()
{
}

// get/set private variable

int		Fixed::getRawBits()	const
{
	return fixed_point;
}

void	Fixed::setRawBits(const int raw)
{
	Fixed::fixed_point = raw;
}

// Convert Fixed-Point to normal variable

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

// Copy assign operator

Fixed&	Fixed::operator=(const Fixed &object)
{	
	Fixed::fixed_point = object.getRawBits();
	return *this;
}

// Comparision Operator

bool	Fixed::operator==(const Fixed &b)
{
	return this->fixed_point == b.getRawBits();
}

bool	Fixed::operator!=(const Fixed &b)
{
	return this->fixed_point != b.getRawBits();
}

bool	Fixed::operator<(const Fixed &b)
{
	return this->fixed_point < b.getRawBits();
}

bool	Fixed::operator<=(const Fixed &b)
{
	return this->fixed_point <= b.getRawBits();
}

bool	Fixed::operator>(const Fixed &b)
{
	return this->fixed_point > b.getRawBits();
}

bool	Fixed::operator>=(const Fixed &b)
{
	return this->fixed_point >= b.getRawBits();
}

// Arithmetric Operator
Fixed	Fixed::operator+(const Fixed &b)
{
	Fixed	res;
	int		raw;

	raw = this->fixed_point + b.getRawBits();
	res.setRawBits(raw);
	return res;
}

Fixed	Fixed::operator-(const Fixed &b)
{
	Fixed	res;
	int		raw;

	raw = this->fixed_point - b.getRawBits();
	res.setRawBits(raw);
	return res;
}

Fixed	Fixed::operator*(const Fixed &b)
{
	Fixed	res;
	int		raw;

	raw = (this->fixed_point * b.getRawBits()) >> Fixed::fraction;
	res.setRawBits(raw);
	return res;
}

Fixed	Fixed::operator/(const Fixed &b)
{
	Fixed	res;
	int		raw;
	int		remider;

	// Check for /0 kind
	if (this->fixed_point == 0 && b.getRawBits() == 0)
	{
		return Fixed(NAN);
	}
	else if (b.getRawBits() == 0)
	{
		return Fixed(INFINITY);
	}
	raw = (this->fixed_point / b.getRawBits()) << Fixed::fraction;

	// Remider Theorem
	remider = this->fixed_point - ((raw * b.getRawBits()) >> Fixed::fraction);
	remider = ((remider << Fixed::fraction) / b.getRawBits());

	// Plus remider to result
	raw += remider;
	res.setRawBits(raw);
	return res;
}

// Increment operator
Fixed&	Fixed::operator++()
{
	++this->fixed_point;
	return *this;
}

Fixed&	Fixed::operator--()
{
	--this->fixed_point;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	res	= *this;
	
	operator++();
	return res;
}

Fixed	Fixed::operator--(int)
{
	Fixed	res	= *this;
	
	operator--();
	return res;
}

// Min/Max Function

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
	{
		return a;
	}
	return b;
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
	{
		return a;
	}
	return b;
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
	{
		return a;
	}
	return b;
}

// Stream Operator

std::ostream&	operator<<(std::ostream &out, const Fixed &object)
{
	out << object.toFloat();
	return out;
}