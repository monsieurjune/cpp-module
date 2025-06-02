/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:01:14 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/29 17:27:33 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_HPP__
#define __SPAN_HPP__
#include <vector>
#include <string>
#include <exception>

class Span
{
    private:
        std::vector<int>    _vec;
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
        class NoSpaceLeftInSpanException : public std::exception
        {
            public:
                explicit NoSpaceLeftInSpanException();
                virtual ~NoSpaceLeftInSpanException() throw();
                virtual const char* what() const throw();
        };

        // span
        int shortestSpan() const;
        int longestSpan() const;

        // add
        void    addNumber(int val);
};

#endif