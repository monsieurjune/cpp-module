/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:22:00 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/16 15:44:50 by tponutha         ###   ########.fr       */
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
        obj.verify_deque();
    }
    catch (std::runtime_error const& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (std::logic_error const& e)
    {
        std::cerr << std::endl;
        std::cerr << "===== LOGIC ERROR ====" << std::endl;
        std::cerr << "Error: " << e.what() << std::endl;
        std::cerr << "======================" << std::endl;
    }
    catch (std::exception const& e)
    {
        std::cerr << std::endl;
        std::cerr << "===== NORMAL ERROR ====" << std::endl;
        std::cerr << "Error: " << e.what() << std::endl;
        std::cerr << "=======================" << std::endl;
    }

    return 0;
}