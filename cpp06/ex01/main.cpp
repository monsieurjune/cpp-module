/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:32:11 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/20 12:42:04 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data*       ptr = NULL;
    Data        test;
    uintptr_t   raw;

    test.a = 1;
    test.b = 2;
    test.c = 3;
    test.d = 4;

    raw = Serializer::serialize(&test);
    std::cout << "Data: " << &test << std::endl;
    std::cout << "Raw: " << raw << std::endl;

    ptr = Serializer::deserialize(raw);
    std::cout << "Content: " 
                << ptr->a << ", " 
                << ptr->b << ", " 
                << ptr->c << ", "
                << ptr->d 
                << std::endl;

    return 0;
}