/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 02:03:53 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/29 03:03:20 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main()
{
    Array<int>  empty;
    Array<int>  normal1(10);
    Array<int>  normal2(20);

    std::cout << "Empty: " << empty.size() << std::endl;
    std::cout << "Normal1: " << normal1.size() << std::endl;
    std::cout << "Normal2: " << normal2.size() << std::endl;

    // modify
    for (unsigned int i = 0; i < normal1.size(); i++)
    {
        normal1[i] = i;
        normal2[i] = i * 4;
    }

    // see
    std::cout << "Normal 1 list" << std::endl;
    for (unsigned int i = 0; i < normal1.size(); i++)
    {
        std::cout << i << ".) " << normal1[i] << std::endl;
    }

    // assign to normal2
    Array<int>  tmp(normal2);

    normal2 = normal1;
    std::cout << "Normal 2 list (old vs new)" << std::endl;
    for (unsigned int i = 0; i < normal1.size(); i++)
    {
        std::cout << i << ".) " << tmp[i] << " - " << normal2[i] << std::endl;
    }

    // try to access wrong place
    try
    {
        normal1[11] = 1;
    }
    catch (std::exception const&)
    {
        std::cout << "Access Wrong place" << std::endl;
    }

    return 0;
}