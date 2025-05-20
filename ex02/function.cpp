/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:58:25 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/20 13:26:32 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>

Base*   generate()
{
    std::srand(std::time(NULL));

    switch (std::rand() % 3)
    {
        case 0:
            return new A;

        case 1:
            return new B;

        default:
            return new C;
    }
}

void    identify(Base *p)
{
    if (dynamic_cast<A*>(p) != NULL)
    {
        std::cout << "A" << std::endl;
        return;
    }
    else if (dynamic_cast<B*>(p) != NULL)
    {
        std::cout << "B" << std::endl;
        return;
    }
    else if (dynamic_cast<C*>(p) != NULL)
    {
        std::cout << "C" << std::endl;
        return;
    }
}

void    identify(Base& p)
{
    try
    {
        A&  a = dynamic_cast<A&>(p);

        (void)a;
        std::cout << "A" << std::endl;
        return;
    }
    catch (std::exception const&)
    {
        // Ignore
    }

    try
    {
        B&  b = dynamic_cast<B&>(p);

        (void)b;
        std::cout << "B" << std::endl;
        return;
    }
    catch (std::exception const&)
    {
        // Ignore
    }

    try
    {
        C&  c = dynamic_cast<C&>(p);

        (void)c;
        std::cout << "C" << std::endl;
        return;
    }
    catch (std::exception const&)
    {
        // Ignore
    }
}