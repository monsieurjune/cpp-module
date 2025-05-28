/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:05:54 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/28 17:43:46 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITER_HPP__
#define __ITER_HPP__
#include <sys/types.h>

template <typename T> void  iter(T* array, size_t n, void (*fn)(T))
{
    for (size_t i = 0; i < n; i++)
    {
        fn(array[i]);
    }
}

#endif