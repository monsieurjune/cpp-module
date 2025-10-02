/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 02:03:53 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/03 22:07:35 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int>  numbers(MAX_VAL);
    int*        mirror = new int[MAX_VAL];

    // set seed
    srand(time(NULL));

    // init array
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    //SCOPE (maybe check deep copy)
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);

        // throw rand value
        for (int i = 0; i < MAX_VAL; i++)
        {
            test[i] = 1;
            tmp[i] = 2;
        }

        // print check
        for (int i = 0; i < MAX_VAL; i++)
        {
            std::cout << numbers[i] << ", " << test[i] << ", " << tmp[i] << std::endl;
        }
    }

    // check value
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    // access negative index
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    // access MAX_INDEX + 1
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;

    return 0;
}