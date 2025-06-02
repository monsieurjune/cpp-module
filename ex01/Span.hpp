/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:01:14 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/03 04:44:11 by tponutha         ###   ########.fr       */
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
            private:
                std::string _msg;

            public:
                explicit NoSpanCanBeFoundException(std::string const& msg);
                virtual ~NoSpanCanBeFoundException() throw();
                virtual const char* what() const throw();
        };

        // full
        class CannotInsertToSpanException : public std::exception
        {
            private:
                std::string _msg;

            public:
                explicit CannotInsertToSpanException(std::string const& msg);
                virtual ~CannotInsertToSpanException() throw();
                virtual const char* what() const throw();
        };

        // getter
        std::multiset<int> const&   getStorage() const;
        unsigned int                getN() const;

        // span
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;

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
                throw Span::CannotInsertToSpanException("Storage isn\'t enough to append whole elements from this container");
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
                throw Span::CannotInsertToSpanException("Storage isn\'t enough to append whole elements from these iterators");
            }

            // insert
            _storage.insert(tmp_set.begin(), tmp_set.end());
        }
};

#endif