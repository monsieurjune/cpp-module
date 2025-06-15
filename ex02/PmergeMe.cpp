/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:21:57 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/15 15:46:52 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cmath>
#include <ctime>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <iostream>

// helper

static inline void sb_inspect_vector(std::string const& head, std::vector<size_t>::const_iterator begin, std::vector<size_t>::const_iterator end)
{
    std::stringstream   ss;

    ss << head;
    for (std::vector<size_t>::const_iterator it = begin; it != end; it++)
    {
        ss << ' ' << *it;
    }

    std::cout << ss.str() << std::endl;
}

static inline void sb_inspect_deque(std::string const& head, std::deque<size_t>::const_iterator begin, std::deque<size_t>::const_iterator end)
{
    std::stringstream   ss;

    ss << head;
    for (std::deque<size_t>::const_iterator it = begin; it != end; it++)
    {
        ss << ' ' << *it;
    }

    std::cout << ss.str() << std::endl;
}

static size_t   sb_delta_usec(struct timespec* start, struct timespec* end)
{
    size_t  u_start = start->tv_sec * 1000000 + start->tv_nsec / 1000;
    size_t  u_end = end->tv_sec * 1000000 + end->tv_nsec / 1000;

    return u_end - u_start;
}

// utils

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

// orthodox

PmergeMe::PmergeMe()
{
    _sort_time_vec_us = 0;
    _sort_time_deque_us = 0;
}

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

    // set time
    _sort_time_vec_us = 0;
    _sort_time_deque_us = 0;

    // if arr is fine, then insert thing to deque later. for performance
    _main_deque.insert(_main_deque.begin() ,_main_vec.begin(), _main_vec.end());
}

PmergeMe::PmergeMe(PmergeMe const& obj) : _main_vec(obj.getVector()), \
                                            _main_deque(obj.getDeque()), \
                                            _sort_time_vec_us(obj.getSortTimeVecUS()),
                                            _sort_time_deque_us(obj.getSortTImeDequeUS())
{
}

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
    _sort_time_vec_us = rhs.getSortTimeVecUS();
    _sort_time_deque_us = rhs.getSortTImeDequeUS();

    return *this;
}

// getter

std::vector<size_t> const&  PmergeMe::getVector() const
{
    return _main_vec;
}

std::deque<size_t> const&   PmergeMe::getDeque() const
{
    return _main_deque;
}

size_t  PmergeMe::getSortTimeVecUS() const
{
    return _sort_time_vec_us;
}

size_t  PmergeMe::getSortTImeDequeUS() const
{
    return _sort_time_deque_us;
}

// public sorter

void    PmergeMe::ford_johnson_sort_vector()
{
    struct timespec t_start;
    struct timespec t_end;

    // get start
    clock_gettime(CLOCK_REALTIME, &t_start);

    // do something
    sort_vector(_main_vec, 1);

    // get end
    clock_gettime(CLOCK_REALTIME, &t_end);
    _sort_time_vec_us = sb_delta_usec(&t_start, &t_end);
}

void    PmergeMe::ford_johnson_sort_deque()
{
    struct timespec t_start;
    struct timespec t_end;

    // get start
    clock_gettime(CLOCK_REALTIME, &t_start);

    // do something
    sort_deque(_main_deque, 1);

    // get end
    clock_gettime(CLOCK_REALTIME, &t_end);
    _sort_time_deque_us = sb_delta_usec(&t_start, &t_end);
}

// verify container

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

// printer

void    PmergeMe::print_vector(std::string const& head) const
{
    sb_inspect_vector(head, _main_vec.begin(), _main_vec.end());
}

void    PmergeMe::print_deque(std::string const& head) const
{
    sb_inspect_deque(head, _main_deque.begin(), _main_deque.end());
}

void    PmergeMe::print_sort_time_vector() const
{
    std::cout << "Time to process a range of " 
                << _main_vec.size() 
                << " elements with std::vector : " 
                << _sort_time_vec_us << " us"
                << std::endl;
}

void    PmergeMe::print_sort_time_deque() const
{
    std::cout << "Time to process a range of " 
                << _main_vec.size() 
                << " elements with std::deque : " 
                << _sort_time_deque_us << " us"
                << std::endl;
}

// sort vec

static inline void  sb_sort_pair(std::vector<size_t>& vec, size_t small_pair_size, size_t big_pair_size)
{
    size_t  big_pair_head_pos = 0;

    while (big_pair_head_pos < vec.size())
    {
        size_t  first_tail_pos = big_pair_head_pos + small_pair_size - 1;
        size_t  second_head_pos = first_tail_pos + 1;
        size_t  second_tail_pos = big_pair_head_pos + big_pair_size - 1;

        // if second doesn't exist, then just stop
        if (second_tail_pos >= vec.size())
        {
            break;
        }

        // swap if first > second
        if (vec[first_tail_pos] > vec[second_tail_pos])
        {
            std::vector<size_t>::iterator   first = vec.begin() + big_pair_head_pos;
            std::vector<size_t>::iterator   middle = vec.begin() + second_head_pos;
            std::vector<size_t>::iterator   end = vec.begin() + second_tail_pos + 1;

            std::rotate(first, middle, end);
        }

        // increment to next big pair
        big_pair_head_pos += big_pair_size;
    }
}

static inline void  sb_filter_pend_out(
                        std::vector<size_t>& main_vec, 
                        std::vector<size_t>& pend_vec, 
                        size_t small_pair_size,
                        size_t big_pair_size,
                        size_t small_pair_amount
                    )
{
    // if only [B1, A1] or [A1] exist in container, then just do nothing
    if (small_pair_amount <= 2)
    {
        return;
    }

    // normal
    std::vector<size_t> aux_main;
    size_t              last_b_head_pos = main_vec.size() - small_pair_size + 1;

    //  small_pair_amount is odd, then last pair is Bm
    //  otherwise, last pair is An
    if (small_pair_amount % 2 == 0)
    {
        last_b_head_pos -= small_pair_size;
    }

    // B1's head position is always 0, and pending must exclude B1 [B2, B3, B4, ... Bm]
    for (size_t i = big_pair_size; i <= last_b_head_pos; i += big_pair_size)
    {
        pend_vec.insert(
            pend_vec.end(), 
            main_vec.begin() + i, 
            main_vec.begin() + i + small_pair_size
        );
    }

    // copy b1 & a[1, N] to aux_main with following order [B1, A1, A2, ... An]
    aux_main.assign(main_vec.begin(), main_vec.begin() + small_pair_size);  // copy B1

    //  copy A[1..n]
    for (size_t i = small_pair_size; i <= last_b_head_pos - small_pair_size; i += big_pair_size)
    {
        aux_main.insert(
            aux_main.end(), 
            main_vec.begin() + i, 
            main_vec.begin() + i + small_pair_size
        );
    }

    // swap aux_main & main
    std::swap(aux_main, main_vec);
}

size_t  PmergeMe::bsearch_upper_vector(std::vector<size_t> const& vec, size_t key, size_t scale_low_pos, size_t scale_high_pos)
{
    (void)vec;
    (void)key;
    (void)scale_low_pos;
    (void)scale_high_pos;
    return 0;
}

void    PmergeMe::sort_vector(std::vector<size_t>& vec, size_t small_pair_size)
{
    size_t  big_pair_size = small_pair_size * 2;

    // recursive check
    if (big_pair_size > vec.size())
    {
        return;
    }

    // merge sort pair
    sb_sort_pair(vec, small_pair_size, big_pair_size);

    // recursive
    sort_vector(vec, big_pair_size);

    // create pend & non_participate_psudo_stack
    std::vector<size_t> pend;
    std::vector<size_t> non_participate_psudo_stack;
    size_t              small_pair_amount = vec.size() / small_pair_size;
    size_t              non_participate_head = small_pair_size * small_pair_amount;

    //  non_participate_psudo_stack
    for (size_t i = vec.size() - 1; i >= non_participate_head; i--)
    {
        non_participate_psudo_stack.push_back(vec.back());
        vec.pop_back();
    }

    //  pend
    sb_filter_pend_out(vec, pend, small_pair_size, big_pair_size, small_pair_amount);

    // binary insertion
    //  jacobsthal logic, binary insert each [Jn, Jn-1), until Jn > M (M is max Bn)
    //  since An > Bn, then end boundary is either An or iterator's end if An doesn't exist
    size_t  jacobsthal_i = 3;
    size_t  jacobsthal_val = jacobsthal(jacobsthal_i);
    size_t  b_m_max = pend.size() / small_pair_size + 1;

    while (jacobsthal_val <= b_m_max)
    {
        size_t  prev_jacobsthal_val = jacobsthal(jacobsthal_i - 1);

        // find & insert Bn to coorect place in main line
        while (jacobsthal_val > prev_jacobsthal_val)
        {
            size_t  pend_b_tail_pos = (jacobsthal_val - 1) * small_pair_size - 1;
            size_t  pend_b_head_pos = pend_b_tail_pos - small_pair_size + 1;
            size_t  scale_high_pos = vec.size() / small_pair_size - 1;
            size_t  insert_pos = bsearch_upper_vector(vec, pend[pend_b_tail_pos], 0, scale_high_pos);

            vec.insert(
                vec.begin() + insert_pos, 
                pend.begin() + pend_b_head_pos, 
                pend.begin() + pend_b_tail_pos + 1
            );
            jacobsthal_val--;
        }

        jacobsthal_i++;
        jacobsthal_val = jacobsthal(jacobsthal_i);
    }

    // append non_participate_psudo_stack back
    while (!non_participate_psudo_stack.empty())
    {
        vec.push_back(non_participate_psudo_stack.back());
        non_participate_psudo_stack.pop_back();
    }
}

// sort deque

void    PmergeMe::sort_deque(std::deque<size_t>& deque, size_t small_pair_size)
{
    (void)deque;
    (void)small_pair_size;
}