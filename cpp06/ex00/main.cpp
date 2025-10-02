/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:45:47 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/20 11:28:22 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>
#include <string>
#include <iostream>

int main(const int argc, const char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        ScalarConverter::convert(argv[i]);
    }
    return 0;
}