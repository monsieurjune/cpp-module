/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 04:54:12 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/04 16:41:08 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANT_STACK_HPP__
#define __MUTANT_STACK_HPP__
#include <stack>
#include <deque>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(std::deque<T> const& obj);
        MutantStack(MutantStack<T> const& rhs);
        ~MutantStack();
        MutantStack&    operator=(MutantStack<T>& rhs);

        // iterator type
        typedef typename std::stack<T>::container_type::iterator                iterator;
        typedef typename std::stack<T>::container_type::const_iterator          const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator        reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator  const_reverse_iterator;

        // iterator
        iterator    begin();
        iterator    end();

        // const iterator
        const_iterator  begin() const;
        const_iterator  end() const;

        // reverse iterator
        reverse_iterator    rbegin();
        reverse_iterator    rend();

        // const reverse iterator
        const_reverse_iterator  rbegin() const;
        const_reverse_iterator  rend() const;
};

#include "MutantStack.tpp"

#endif
