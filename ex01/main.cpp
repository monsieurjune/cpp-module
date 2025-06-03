/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:02:58 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/03 20:30:23 by tponutha         ###   ########.fr       */
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
    }
}

int main(int argc, char* argv[])
{
    // print before
    std::cout << "==== PRINT1 ====" << std::endl;
    ::iter(argv, argc, &print);
    std::cout << std::endl;

    // change
    ::iter(argv, argc, &change);

    // print after
    std::cout << "==== PRINT2 ====" << std::endl;
    ::iter(argv, argc, &print);

    return 0;
}
