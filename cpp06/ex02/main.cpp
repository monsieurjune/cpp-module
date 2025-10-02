/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:22:30 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/20 13:24:57 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.hpp"
#include <exception>

int main()
{
    try
    {
        Base*   ptr = generate();
        Base&   ref = *ptr;

        (void)ptr;
        (void)ref;
        identify(ptr);
        identify(ref);

        delete ptr;
    }
    catch (std::exception const&)
    {
        return 1;
    }
    return 0;
}