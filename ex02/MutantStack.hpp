/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 04:54:12 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/03 07:11:52 by tponutha         ###   ########.fr       */
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

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(std::deque<T> const& obj) : std::stack<T>(obj) {}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const& rhs) : std::stack<T>(rhs) {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack<T>& rhs)
{
    if (&rhs == this)
    {
        return *this;
    }

    std::stack<T>::operator=(rhs);

    return *this;
}

// iterator

template <typename T>
typename MutantStack<T>::iterator    MutantStack<T>::begin() { return this->c.begin(); }

template <typename T>
typename MutantStack<T>::iterator    MutantStack<T>::end() { return this->c.end(); }

// const iterator

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const { return this->c.begin(); }

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const { return this->c.end(); }

// reverse iterator

template <typename T>
typename MutantStack<T>::reverse_iterator   MutantStack<T>::rbegin() { return this->c.rbegin(); }

template <typename T>
typename MutantStack<T>::reverse_iterator   MutantStack<T>::rend() { return this->c.rend(); }

// const reverse iterator

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const { return this->c.rbegin(); }

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const { return this->c.rend(); }

#endif