/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:21:54 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/15 19:09:21 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGE_ME_HPP__
#define __PMERGE_ME_HPP__
#include <string>
#include <vector>
#include <deque>

class PmergeMe
{
    private:
        // first container
        std::vector<size_t> _main_vec;

        // secend container
        std::deque<size_t>  _main_deque;

        // time
        size_t  _sort_time_vec_us;
        size_t  _sort_time_deque_us;

        // method
        static size_t   to_ulong(std::string const& str);
        static size_t   jacobsthal(size_t n);

        // vec sort
        static size_t   bsearch_upper_vector(std::vector<size_t> const& vec, size_t key, size_t scale_low_pos, size_t scale_high_pos, size_t small_pair_size);
        static void     insert_b_vector(std::vector<size_t>& main_vec, std::vector<size_t>& pend_vec, size_t small_pair_size);
        static void     sort_vector(std::vector<size_t>& vec, size_t small_pair_size);

        // deque sort
        static void     sort_deque(std::deque<size_t>& deque, size_t small_pair_size);

    public:
        PmergeMe();
        PmergeMe(const int n, const char* arr[]);
        PmergeMe(PmergeMe const& obj);
        ~PmergeMe();
        PmergeMe&   operator=(PmergeMe const& rhs);

        // sort
        void    ford_johnson_sort_vector();
        void    ford_johnson_sort_deque();

        // verify
        void    verify_vector() const;
        void    verify_deque() const;

        // print
        void    print_vector(std::string const& head) const;
        void    print_deque(std::string const& head) const;
        void    print_sort_time_vector() const;
        void    print_sort_time_deque() const;

        // getter
        std::vector<size_t> const&  getVector() const;
        std::deque<size_t> const&   getDeque() const;
        size_t  getSortTimeVecUS() const;
        size_t  getSortTImeDequeUS() const;
};

#endif