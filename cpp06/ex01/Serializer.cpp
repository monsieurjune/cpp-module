/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:24:37 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/20 12:40:03 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t   Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data*   Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}