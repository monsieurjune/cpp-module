/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:21:57 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/13 19:25:02 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cmath>
#include <ctime>
#include <stdexcept>
#include <sstream>
#include <iostream>

size_t  PmergeMe::to_ulong(std::string const& str)
{
    // check number
    for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
    {
        if (*it < '0' || *it > '9')
        {
            throw std::runtime_error("Found non number");
        }
    }

    // normal
    std::stringstream   ss;
    size_t              ret;

    ss << str;
    ss >> ret;

    return ret;
}

size_t  PmergeMe::jacobsthal(size_t n)
{
    return (static_cast<size_t>(std::pow(2, n)) - static_cast<size_t>(std::pow(-1, n))) / 3;
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const int n, const char* arr[])
{
    if (n < 2)
    {
        throw std::runtime_error("Argument Error");
    }

    for (int i = 1; i < n; i++)
    {
        size_t  val = to_ulong(arr[i]);

        _main_vec.push_back(val);
    }

    // if arr is fine, then insert thing to deque later. for performance
    _main_deque.insert(_main_deque.begin() ,_main_vec.begin(), _main_vec.end());
}

PmergeMe::PmergeMe(PmergeMe const& obj) : _main_vec(obj.getVector()), _main_deque(obj.getDeque()) {}

PmergeMe::~PmergeMe() {}

PmergeMe&   PmergeMe::operator=(PmergeMe const& rhs)
{
    if (&rhs == this)
    {
        return *this;
    }

    // normal
    _main_vec = rhs.getVector();
    _main_deque = rhs.getDeque();

    return *this;
}

std::vector<size_t> const&  PmergeMe::getVector() const
{
    return _main_vec;
}

std::deque<size_t> const&   PmergeMe::getDeque() const
{
    return _main_deque;
}

static size_t   sb_delta_usec(struct timespec* start, struct timespec* end)
{
    size_t  u_start = start->tv_sec * 1000000 + start->tv_nsec / 1000;
    size_t  u_end = end->tv_sec * 1000000 + end->tv_nsec / 1000;

    return u_end - u_start;
}

void    PmergeMe::ford_johnson_sort_vector()
{
    struct timespec t_start;
    struct timespec t_end;

    clock_gettime(CLOCK_REALTIME, &t_start);

    // do something

    clock_gettime(CLOCK_REALTIME, &t_end);
    std::cout << "Time to process a range of " 
                << _main_vec.size() 
                << " elements with std::vector : " 
                << sb_delta_usec(&t_start, &t_end) << " us"
                << std::endl;
}

void    PmergeMe::ford_johnson_sort_deque()
{
    struct timespec t_start;
    struct timespec t_end;

    clock_gettime(CLOCK_REALTIME, &t_start);

    // do something

    clock_gettime(CLOCK_REALTIME, &t_end);
    std::cout << "Time to process a range of " 
                << _main_vec.size() 
                << " elements with std::deque : " 
                << sb_delta_usec(&t_start, &t_end) << " us"
                << std::endl;
}

void    PmergeMe::verify_vector() const
{
    for (std::vector<size_t>::const_iterator it = _main_vec.begin(); it != _main_vec.end(); it++)
    {
        std::vector<size_t>::const_iterator it_next = it;

        it_next++;
        if (it_next != _main_vec.end())
        {
            if (*it > *it_next)
            {
                throw std::logic_error("This Vector isn't sorted properly");
            }
        }
        else
        {
            break;
        }
    }
}

void    PmergeMe::verify_deque() const
{
    for (std::deque<size_t>::const_iterator it = _main_deque.begin(); it != _main_deque.end(); it++)
    {
        std::deque<size_t>::const_iterator it_next = it;

        it_next++;
        if (it_next != _main_deque.end())
        {
            if (*it > *it_next)
            {
                throw std::logic_error("This Deque isn't sorted properly");
            }
        }
        else
        {
            break;
        }
    }
}

void    PmergeMe::print_vector(std::string const& head) const
{
    std::stringstream   ss;

    ss << head;
    for (std::vector<size_t>::const_iterator it = _main_vec.begin(); it != _main_vec.end(); it++)
    {
        ss << " " << *it;
    }

    std::cout << ss.str() << std::endl;
}

void    PmergeMe::print_deque(std::string const& head) const
{
    std::stringstream   ss;

    ss << head;
    for (std::deque<size_t>::const_iterator it = _main_deque.begin(); it != _main_deque.end(); it++)
    {
        ss << " " << *it;
    }

    std::cout << ss.str() << std::endl;
}