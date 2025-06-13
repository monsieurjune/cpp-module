/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:21:54 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/13 19:25:00 by tponutha         ###   ########.fr       */
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

        // method
        size_t  to_ulong(std::string const& str);
        size_t  jacobsthal(size_t n);

        // vec sort
        void    sort_vector(std::vector<size_t>& vec);

        // deque sort
        void    sort_deque(std::deque<size_t>& deque);

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

        // getter
        std::vector<size_t> const&  getVector() const;
        std::deque<size_t> const&   getDeque() const;
};

#endif