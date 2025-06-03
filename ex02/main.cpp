/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 03:08:42 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/04 02:11:48 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <stack>
#include <list>
#include <iostream>

static void sb_stack()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << ", Size: " << mstack.size() << std::endl;
    mstack.pop();
    std::cout << "Top: " << mstack.top() << ", Size: " << mstack.size() << std::endl;

    // append stack
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(-1232);
    mstack.push(667);
    mstack.push(667);
    mstack.push(0);

    // prepare to loop
    size_t                      i = 0;
    MutantStack<int>::iterator  it = mstack.begin();
    MutantStack<int>::iterator  ite = mstack.end();

    // just doing weird thing here
    ++it;
    --it;

    // iterate (it's iterating in deque way, first -> last, not last -> first like how stack work)
    while (it != ite)
    {
        std::cout << i << ".) " << *it << std::endl;
        i++;
        ++it;
    }

    // test polymorphism
    std::stack<int> s(mstack);
}

static void sb_list()
{
    std::list<int> mstack;

    mstack.push_back(5);
    mstack.push_back(17);

    std::cout << "Top: " << mstack.back() << ", Size: " << mstack.size() << std::endl;
    mstack.pop_back();
    std::cout << "Top: " << mstack.back() << ", Size: " << mstack.size() << std::endl;

    // append stack
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(-1232);
    mstack.push_back(667);
    mstack.push_back(667);
    mstack.push_back(0);

    // prepare to loop
    size_t                      i = 0;
    std::list<int>::iterator    it = mstack.begin();
    std::list<int>::iterator    ite = mstack.end();

    // just doing weird thing here
    ++it;
    --it;

    // iterate (it's iterating in deque way, first -> last, not last -> first like how stack work)
    while (it != ite)
    {
        std::cout << i << ".) " << *it << std::endl;
        i++;
        ++it;
    }
}

int main()
{
    // stack
    std::cout << "===== STACK ====" << std::endl;
    sb_stack();
    std::cout << "================" << std::endl;
    std::cout << std::endl;

    // list
    std::cout << "===== LISTS ====" << std::endl;
    sb_list();
    std::cout << "================" << std::endl;

    return 0;
}