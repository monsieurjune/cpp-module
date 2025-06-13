/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:52:22 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/13 11:25:39 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <sstream>

int main(const int argc, const char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Error" << std::endl;
        return 1;
    }

    // the rest
    std::string         buff;
    std::stringstream   ss(argv[1]);

    while (std::getline(ss, buff, ' '))
    {
        if (buff.empty())
        {
            continue;
        }

        if (buff.length() > 1)
        {
            std::cout << "Error" << std::endl;
            break;
        }
    }

    return 0;
}