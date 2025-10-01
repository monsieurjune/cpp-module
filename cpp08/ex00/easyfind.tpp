/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:50:02 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/11 19:12:18 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_TPP__
#define __EASYFIND_TPP__
#include <algorithm>
#include <stdexcept>

template <typename T>
int easyfind(T data, int val)
{
    typename T::const_iterator it = std::find(data.begin(), data.end(), val);

    if (it == data.end())
    {
        throw std::out_of_range("Cannot found value");
    }

    return *it;
}

#endif
