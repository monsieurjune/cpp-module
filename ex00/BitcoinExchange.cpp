/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 02:28:48 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/05 07:38:13 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _isObjValid(true) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& rhs) : _mapPriceByDate(rhs.getMapPriceByDate()),\
                                                                _isObjValid(rhs.isValid())
{
}

BitcoinExchange::BitcoinExchange(std::ifstream const& dbfile)
{
    readDB(dbfile);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&    BitcoinExchange::operator=(BitcoinExchange const& rhs)
{
    if (&rhs == this)
    {
        return *this;
    }

    _mapPriceByDate = rhs.getMapPriceByDate();
    _isObjValid = rhs.isValid();

    return *this;
}

bool    BitcoinExchange::isValid() const
{
    return _isObjValid;
}

std::map<std::string, double> const&    BitcoinExchange::getMapPriceByDate() const
{
    return _mapPriceByDate;
}

