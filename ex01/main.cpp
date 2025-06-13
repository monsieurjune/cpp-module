/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 03:08:42 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/13 12:12:10 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <sstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

static void	sb_print(Span const& sp1, Span const& sp2)
{
	std::multiset<int> const&	s1_ref = sp1.getStorage();
	std::multiset<int> const&	s2_ref = sp2.getStorage();

	// iterator
	std::multiset<int>::const_iterator	s1_it = s1_ref.begin();
	std::multiset<int>::const_iterator	s1_end = s1_ref.end();
	std::multiset<int>::const_iterator	s2_it = s2_ref.begin();
	std::multiset<int>::const_iterator	s2_end = s2_ref.end();

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
}

static void	sb_tutorial()
{
	Span	sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "==== TUTORIAL ====" << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "==================" << std::endl << std::endl;
}

static void	sb_deepcopy(std::vector<int> const& vec)
{
	Span	sp0 = Span(10);
	Span	sp1 = Span(3);

	// start
	std::cout << "==== DEEPCOPY ====" << std::endl;

	// fill
	sp0.addNumber(vec.begin(), vec.begin() + 4);
	sp1.addNumber(vec.begin() + 6, vec.begin() + 7);

	// print
	sb_print(sp0, sp1);

	// copy assignment
	sp1 = sp0;
	sp1.addNumber(0);
	sp1.addNumber(1);

	// print
	std::cout << std::endl;
	sb_print(sp0, sp1);
	std::cout << std::endl;

	// scope
	{
		Span	sp2(sp1);

		sp2.addNumber(vec.begin() + 8, vec.begin() + 9);

		// print
		sb_print(sp1, sp2);
	}

	// end
	std::cout << "==================" << std::endl << std::endl;
}

static void	sb_minmax()
{
	Span	sp0 = Span(10);

	// start
	std::cout << "==== LIMIT ====" << std::endl;

	sp0.addNumber(2147483647);
	sp0.addNumber(-2147483648);
	std::cout << "SHORTEST: " << sp0.shortestSpan() << std::endl;
	std::cout << "LONGEST: " << sp0.longestSpan() << std::endl;
	std::cout << std::endl;

	sp0.addNumber(0);
	std::cout << "SHORTEST: " << sp0.shortestSpan() << std::endl;
	std::cout << "LONGEST: " << sp0.longestSpan() << std::endl;
	std::cout << std::endl;

	sp0.addNumber(-2147483647);
	std::cout << "SHORTEST: " << sp0.shortestSpan() << std::endl;
	std::cout << "LONGEST: " << sp0.longestSpan() << std::endl;

	// end
	std::cout << "==================" << std::endl << std::endl;
}

static void	sb_exception(std::vector<int> const& vec)
{
	// start
	std::cout << "==== EXCEPTION ====" << std::endl;

	try
	{
		Span	sp0 = Span(16);

		std::cout << "Add [0, 3]" << std::endl;
		sp0.addNumber(vec.begin(), vec.begin() + 4);

		std::cout << "Add [4, 15]" << std::endl;
		sp0.addNumber(vec.begin(), vec.begin() + 20);

		std::cout << "Add [16, 17]" << std::endl;
		sp0.addNumber(vec.begin(), vec.begin() + 20);

		std::cout << "Add [17, 30]" << std::endl;
		sp0.addNumber(vec.begin(), vec.begin() + 20);
	}
	catch (Span::CannotInsertToSpanException const& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	try
	{
		Span			sp0 = Span(16);
		unsigned int 	shortest;
		unsigned int	longest;

		shortest = sp0.shortestSpan();
		longest = sp0.longestSpan();
		std::cout << "SHORTEST: " << shortest << std::endl;
		std::cout << "LONGEST: " << longest << std::endl;
	}
	catch (Span::NoSpanCanBeFoundException const& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	try
	{
		Span			sp0	= Span(16);
		unsigned int 	shortest;
		unsigned int	longest;

		sp0.addNumber(1);
		shortest = sp0.shortestSpan();
		longest = sp0.longestSpan();
		std::cout << "SHORTEST: " << shortest << std::endl;
		std::cout << "LONGEST: " << longest << std::endl;
	}
	catch (Span::NoSpanCanBeFoundException const& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	// end
	std::cout << "==================" << std::endl << std::endl;
}

static void	sb_normal(std::vector<int> const& vec)
{
	int		n = 10001;
	Span	sp0 = Span(n);

	// start
	std::cout << "==== NORMAL ====" << std::endl;

	sp0.addNumber(vec.begin(), vec.begin() + 2);
	for (int i = 0; i < n; i++)
	{
		try
		{
			sp0.addNumber(std::rand());
		}
		catch (Span::CannotInsertToSpanException const& e)
		{
			break;
		}
	}

	// print
	std::cout << "SHORTEST: " << sp0.shortestSpan() << std::endl;
	std::cout << "LONGEST: " << sp0.longestSpan() << std::endl;

	// end
	std::cout << "==================" << std::endl << std::endl;
}

int main()
{
	std::vector<int>	vec0;

	std::srand(std::time(NULL));
	for (int i = 0; i < 30; i++)
	{
		vec0.push_back(std::rand());
	}

	sb_tutorial();
	sb_deepcopy(vec0);
	sb_minmax();
	sb_exception(vec0);
	sb_normal(vec0);
	return 0;
}
