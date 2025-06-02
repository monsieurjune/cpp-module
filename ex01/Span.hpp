/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:01:14 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/03 03:22:27 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_HPP__
#define __SPAN_HPP__
#include <set>
#include <string>
#include <exception>

class Span
{
    private:
        std::multiset<int>  _storage;
        unsigned int        _n;

    public:
        Span();
        Span(Span const& rhs);
        Span(unsigned int n);
        ~Span();
        Span&   operator=(Span const& rhs);

        // exception
        // no span
        class NoSpanCanBeFoundException : public std::exception
        {
            public:
                explicit NoSpanCanBeFoundException();
                virtual ~NoSpanCanBeFoundException() throw();
                virtual const char* what() const throw();
        };

        // full
        class CannotInsertToSpanException : public std::exception
        {
            public:
                explicit CannotInsertToSpanException();
                virtual ~CannotInsertToSpanException() throw();
                virtual const char* what() const throw();
        };

        // span
        int shortestSpan() const;
        int longestSpan() const;

        // add
        void    addNumber(int val);

        template <typename C>
        void    addNumber(C const& container)
        {
            std::multiset<int>  tmp_set;
            unsigned int        total_size = _storage.size();

            // insert to tmp
            tmp_set.insert(container.begin(), container.end());
            total_size += tmp_set.size();

            // check
            if (total_size > _n)
            {
                throw CannotInsertToSpanException();
            }

            // insert
            _storage.insert(tmp_set.begin(), tmp_set.end());
        }

        template <typename C>
        void    addNumber(typename C::const_iterator begin, typename C::const_iterator end)
        {
            std::multiset<int>  tmp_set;
            unsigned int        total_size = _storage.size();

            // insert to tmp
            tmp_set.insert(begin, end);
            total_size += tmp_set.size();

            // check
            if (total_size > _n)
            {
                throw CannotInsertToSpanException();
            }

            // insert
            _storage.insert(tmp_set.begin(), tmp_set.end());
        }
};

#endif