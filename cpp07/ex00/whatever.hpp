/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:54:20 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/03 22:12:21 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WHATEVER_HPP__
#define __WHATEVER_HPP__

template <typename T>
void swap(T& a, T& b)
{
    T   temp = a;

    a = b;
    b = temp;
}

template <typename T>
T const& min(T const& a, T const& b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}

template <typename T>
T const& max(T const& a, T const& b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

#endif