/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 03:08:42 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/07 19:35:33 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <stack>
#include <list>
#include <iostream>
#include <sstream>

static void	sb_print(MutantStack<int> const& sp1, MutantStack<int> const& sp2)
{
	// iterator
	MutantStack<int>::const_iterator	s1_it = sp1.begin();
	MutantStack<int>::const_iterator	s1_end = sp1.end();
	MutantStack<int>::const_iterator	s2_it = sp2.begin();
	MutantStack<int>::const_iterator	s2_end = sp2.end();

	std::cout << " s1 | s2 " << std::endl;
	while (s1_it != s1_end || s2_it != s2_end)
	{
		std::stringstream	ss;

		// increment s1
		if (s1_it != s1_end)
		{
			ss << *s1_it;
			s1_it++;
		}
		else
		{
			ss << "[NONE]";
		}

		// center
		ss << " - ";

		// increment s2
		if (s2_it != s2_end)
		{
			ss << *s2_it;
			s2_it++;
		}
		else
		{
			ss << "[NONE]";
		}

		std::cout << ss.str() << std::endl;
	}
    std::cout << std::endl;
}

static void sb_deepcopy()
{
    MutantStack<int>    mstack;
    MutantStack<int>    mstack1;

    mstack1.push(0);
    mstack.push(5);
    mstack.push(17);

    sb_print(mstack, mstack1);
    mstack1 = mstack;
    sb_print(mstack, mstack1);
    mstack1.pop();
    mstack1.push(1);
    mstack.pop();
    sb_print(mstack, mstack1);

    {
        MutantStack<int>    mstack2(mstack1);

        mstack2.push(3);
        mstack2.push(4);
        sb_print(mstack1, mstack2);
    }
}

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
    // deepcopy
    std::cout << "===== DEEPCOPY ====" << std::endl;
    sb_deepcopy();
    std::cout << "===================" << std::endl;
    std::cout << std::endl;

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
