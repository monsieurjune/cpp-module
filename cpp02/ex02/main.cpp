/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:38:02 by tponutha          #+#    #+#             */
/*   Updated: 2023/11/13 16:46:32 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( -5.05f ) / Fixed( 2 ) );
	Fixed const c( Fixed( -5.05f ) + Fixed( 2 ));

	std::cout << "Before : " <<  a << std::endl;
	std::cout << "Pre-inc : " << ++a << std::endl;
	std::cout << "Before : " << a << std::endl;
	std::cout << "Post-inc : " << a++ << std::endl;
	std::cout << "A : " << a << std::endl;
	std::cout << "B : " << b << std::endl;
	std::cout << "C : " << c << std::endl;
	std::cout << "Max : " << Fixed::max(a, b) << std::endl;

	bool	res;

	res = a == b;
	std::cout << "A == B : " << res<< std::endl;
	res = a != b;
	std::cout << "A != B : " << res<< std::endl;
	res = a > b;
	std::cout << "A > B : " << res<< std::endl;
	res = a >= b;
	std::cout << "A >= B : " << res<< std::endl;
	res = a < b;
	std::cout << "A < B : " << res<< std::endl;
	res = a <= b;
	std::cout << "A <= B : " << res<< std::endl;
	return 0;
}