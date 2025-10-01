/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 03:08:42 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/04 16:42:38 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <deque>

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

static void sb_find(std::list<int> const& vec, int find)
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

static void sb_find(std::set<int> const& vec, int find)
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

static void sb_find(std::deque<int> const& vec, int find)
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

static inline void sb_vector()
{
    std::vector<int> obj;

    // assign
    obj.push_back(1);
    obj.push_back(2);
    obj.push_back(3);
    obj.push_back(4);

    // test
    std::cout << "===== VECTOR =====" << std::endl;
    sb_find(obj, 0);
    sb_find(obj, 1);
    sb_find(obj, 2);
    sb_find(obj, 3);
    sb_find(obj, 4);
    sb_find(obj, 5);
    std::cout << "==================" << std::endl << std::endl;
}

static inline void  sb_list()
{
    std::list<int>  obj;

    // assign
    obj.push_back(1);
    obj.push_front(2);
    obj.push_front(3);
    obj.push_back(4);

        // test
    std::cout << "===== LIST =====" << std::endl;
    sb_find(obj, 0);
    sb_find(obj, 1);
    sb_find(obj, 2);
    sb_find(obj, 3);
    sb_find(obj, 4);
    sb_find(obj, 5);
    std::cout << "================" << std::endl << std::endl;
}

static inline void  sb_set()
{
    std::set<int>  obj;

    // assign
    obj.insert(1);
    obj.insert(2);
    obj.insert(3);
    obj.insert(4);

        // test
    std::cout << "===== SET =====" << std::endl;
    sb_find(obj, 0);
    sb_find(obj, 1);
    sb_find(obj, 2);
    sb_find(obj, 3);
    sb_find(obj, 4);
    sb_find(obj, 5);
    std::cout << "===============" << std::endl << std::endl;
}

static inline void  sb_queue()
{
    std::deque<int>  obj;

    // assign
    obj.push_back(1);
    obj.push_back(2);
    obj.push_front(3);
    obj.push_back(4);

        // test
    std::cout << "===== DEQUE =====" << std::endl;
    sb_find(obj, 0);
    sb_find(obj, 1);
    sb_find(obj, 2);
    sb_find(obj, 3);
    sb_find(obj, 4);
    sb_find(obj, 5);
    std::cout << "=================" << std::endl << std::endl;
}

int main()
{
    sb_vector();
    sb_list();
    sb_queue();
    sb_set();
    return 0;
}
