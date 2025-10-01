/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:27:03 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/16 15:53:27 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stdexcept>

RPN::RPN() {}

RPN::RPN(RPN const& obj) : _stack(obj.getStack()) {}

RPN::~RPN() {}

RPN&    RPN::operator=(RPN const& rhs)
{
    if (&rhs == this)
    {
        return *this;
    }

    _stack = rhs.getStack();

    return *this;
}

std::stack<ssize_t> const&  RPN::getStack() const
{
    return _stack;
}

void    RPN::add(std::string const& str)
{
    if (str.length() != 1)
    {
        throw std::runtime_error("Try to push >1 wide string to stack");
    }

    // normal
    char    c = str[0];

    if (!pushNumber(c))
    {
        pushOperator(c);

        // check if stack_size >= 3
        if (_stack.size() < 3)
        {
            throw std::runtime_error("Try to calculate with stack's size < 3");
        }

        // calculate
        calculate();
    }
}

ssize_t    RPN::ans()
{
    if (_stack.size() != 1)
    {
        throw std::runtime_error("Stack Size isn't equal to 1 when calculation is over");
    }

    return _stack.top();
}

bool    RPN::pushNumber(char c)
{
    if (c < '0' || c > '9')
    {
        return false;
    }

    ssize_t val = static_cast<ssize_t>(c) - static_cast<ssize_t>('0');

    _stack.push(val);

    return true;
}

void    RPN::pushOperator(char c)
{
    if (c != '+' && c != '-' && c != '*' && c != '/')
    {
        throw std::runtime_error("Try to push unknown operator");
    }

    _stack.push(static_cast<ssize_t>(c));
}

void    RPN::calculate()
{
    char    oper;
    ssize_t y;
    ssize_t x;
    ssize_t z;

    // operator
    oper = static_cast<char>(_stack.top());
    _stack.pop();

    // y
    y = _stack.top();
    _stack.pop();

    // x
    x = _stack.top();
    _stack.pop();

    switch (oper)
    {
        case '+':
            z = x + y;
            break;
        case '-':
            z = x - y;
            break;
        case '*':
            z = x * y;
            break;
        case '/':
            if (y == 0)
                throw std::runtime_error("Try to divide by zero");
            z = x / y;
            break;
        default:
            throw std::logic_error("Detect unknown operator in RPN::calculator() (fix bug!)");
    }

    _stack.push(z);
}
