/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 02:14:02 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/03 22:09:04 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_TPP__
#define __ARRAY_TPP__
#include <exception>

template <typename T>
Array<T>::Array() : _array(new T[0]), _n(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _n(n)
{
    for (unsigned int i = 0; i < _n; i++)
    {
        _array[i] = 0;
    }
}

template <typename T>
Array<T>::Array(Array<T>& rhs) : _array(new T[rhs.size()]), _n(rhs.size())
{
    for (unsigned int i = 0; i < _n; i++)
    {
        _array[i] = rhs[i];
    }
}

template <typename T>
Array<T>::~Array()
{
    delete[] _array;
}

template <typename T>
Array<T>&   Array<T>::operator=(Array<T>& rhs)
{
    // prevent reallocate same object
    if (&rhs == this)
    {
        return *this;
    }

    // normal part
    T*  tmp = new T[rhs.size()];

    delete[] _array;
    _array = tmp;
    _n = rhs.size();

    for (unsigned int i = 0; i < _n; i++)
    {
        _array[i] = rhs[i];
    }

    return *this;
}

template <typename T>
unsigned int    Array<T>::size() const
{
    return _n;
}

template <typename T>
T&  Array<T>::operator[](unsigned int i)
{
    if (i >= _n)
    {
        throw std::exception();
    }

    return _array[i];
}

#endif