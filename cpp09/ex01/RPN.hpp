/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:27:11 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/13 14:13:19 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RPN_HPP__
#define __RPN_HPP__
#include <string>
#include <stack>
#include <sys/types.h>

class RPN
{
    private:
        std::stack<ssize_t>    _stack;

        // math
        void    calculate();

        // condition
        bool    pushNumber(char c);
        void    pushOperator(char c);

    public:
        RPN();
        RPN(RPN const& obj);
        ~RPN();
        RPN&    operator=(RPN const& rhs);

        // getter
        std::stack<ssize_t> const&  getStack() const;

        // math
        void    add(std::string const& str);
        ssize_t ans();
};

#endif