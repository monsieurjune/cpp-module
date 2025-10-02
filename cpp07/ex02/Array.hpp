/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 02:03:34 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/29 03:04:16 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

template <typename T> class Array
{
    private:
        T*              _array;
        unsigned int    _n;

    public:
        Array();
        Array(unsigned int n);
        Array(Array& rhs);
        ~Array();
        Array&  operator=(Array& rhs);

        // getter
        unsigned int    size() const;

        // access
        T&  operator[](unsigned int i);
};

#include "Array.tpp"

#endif