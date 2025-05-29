/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 03:08:42 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/29 14:43:35 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

static void sb_find(std::vector<int> const& vec, int find)
{
    try
    {
        int found = ::easyfind(vec, find);

        std::cout << "Find: " << find << " [found: " << found << "]" << std::endl;
    }
    catch (std::exception const&)
    {
        std::cout << "Find: " << find << " [not found]" << std::endl;
    }
}

int main()
{
    std::vector<int> vec;

    // assign
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    sb_find(vec, 0);
    sb_find(vec, 1);
    sb_find(vec, 2);
    sb_find(vec, 3);
    sb_find(vec, 4);
    sb_find(vec, 5);
    return 0;
}