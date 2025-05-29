/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:50:02 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/29 14:57:26 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_TPP__
#define __EASYFIND_TPP__
#include <algorithm>
#include <exception>

template <typename C>
int easyfind(C const& data, int val)
{
    typename C::const_iterator it = std::find(data.begin(), data.end(), val);

    if (it == data.end())
    {
        throw std::exception();
    }

    return *it;
}

#endif