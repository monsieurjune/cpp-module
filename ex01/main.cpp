/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:02:58 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/28 17:46:07 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

static void print(char* c)
{
    std::cout << c << std::endl;
}

static void change(char* c)
{
    if (c[0] != '\0')
    {
        c[0] = '!';
        std::cout << c << std::endl;
    }
}

int main(int argc, char* argv[])
{
    std::cout << "==== PRINT ====" << std::endl;
    ::iter(argv, argc, &print);
    std::cout << std::endl;

    std::cout << "==== CHANGE ====" << std::endl;
    ::iter(argv, argc, &change);

    return 0;
}
