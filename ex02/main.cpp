/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:22:00 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/16 06:06:39 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>

int main(const int argc, const char* argv[])
{
    try
    {
        PmergeMe    obj(argc, argv);

        obj.print_vector("Before:");
        obj.ford_johnson_sort_vector();
        obj.ford_johnson_sort_deque();
        obj.print_vector("After:");
        obj.print_sort_time_vector();
        obj.print_sort_time_deque();
        obj.verify_vector();
    }
    catch (std::runtime_error const& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (std::logic_error const& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (std::exception const& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}