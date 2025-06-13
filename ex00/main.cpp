/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 02:29:28 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/13 09:48:37 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(const int argc, const char* argv[])
{
    BitcoinExchange obj0("data.csv");
    std::string     filename;

    if (argc >= 2)
    {
        filename.assign(argv[1]);
    }
    obj0.analyze(filename);

    return 0;
}