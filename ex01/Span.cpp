/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:01:29 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/03 04:44:40 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// orthodox

Span::Span() : _n(0) {}

Span::Span(Span const& rhs) : _storage(rhs.getStorage()), _n(rhs.getN()) {}

Span::Span(unsigned int n) : _n(n) {}

Span::~Span() {}

Span&   Span::operator=(Span const& rhs)
{
    // avoid copy to itself
    if (&rhs == this)
    {
        return *this;
    }

    //copy
    std::multiset<int> const&   obj = rhs.getStorage();

    _storage.clear();
    _storage.insert(obj.begin(), obj.end());
    _n = rhs.getN();

    return *this;
}

// Exception

Span::NoSpanCanBeFoundException::NoSpanCanBeFoundException(std::string const& msg) : _msg(msg) {}

Span::NoSpanCanBeFoundException::~NoSpanCanBeFoundException() throw() {}

const char* Span::NoSpanCanBeFoundException::what() const throw() { return _msg.c_str(); }

Span::CannotInsertToSpanException::CannotInsertToSpanException(std::string const& msg) : _msg(msg) {}

Span::CannotInsertToSpanException::~CannotInsertToSpanException() throw() {}

const char* Span::CannotInsertToSpanException::what() const throw() { return _msg.c_str(); }

// getter

std::multiset<int> const&   Span::getStorage() const
{
    return _storage;
}

unsigned int    Span::getN() const
{
    return _n;
}

// span

unsigned int Span::shortestSpan() const
{
    unsigned int min = __UINT32_MAX__;

    if (_storage.size() <= 1)
    {
        throw Span::NoSpanCanBeFoundException("Can\'t calculate shrotest span with less than 2 elements");
    }

    for (std::multiset<int>::const_iterator it = _storage.begin(); it != _storage.end(); it++)
    {
        std::multiset<int>::const_iterator  next_it = it;
        unsigned int                        cmp;

        next_it++;  // this line existed because i'm not sure that it++ would assign "next it" to next_it

        // just skip, if next_it is the end. indicate that there is no element to compare further
        if (next_it == _storage.end())
        {
            break;
        }

        // compare (100% no negative mathematically, as this is sorted iterator)
        cmp = *next_it - *it;

        // check
        if (cmp < min)
        {
            min = cmp;
        }
    }

    return min;
}

unsigned int Span::longestSpan() const
{
    if (_storage.size() <= 1)
    {
        throw Span::NoSpanCanBeFoundException("Can\'t calculate longest span with less than 2 elements");
    }

    // according to math, distance between max and min in sorted set is the longest span
    std::multiset<int>::const_iterator  first = _storage.begin();
    std::multiset<int>::const_iterator  last = _storage.end();

    last--; // this line existed because i'm not sure that it-- would assign "prev it" to last

    return *last - *first;
}

void    Span::addNumber(int val)
{
    if (_storage.size() + 1 > _n)
    {
        throw Span::CannotInsertToSpanException("Storage isn\'t enough to append 1 element");
    }

    _storage.insert(val);
}