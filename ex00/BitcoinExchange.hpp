/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 02:28:45 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/13 06:13:07 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOIN_EXCHANGE_HPP__
#define __BITCOIN_EXCHANGE_HPP__
#include <string>
#include <fstream>
#include <map>

class BitcoinExchange
{
    private:
        static double   _min_value;
        static double   _max_value;

        std::map<size_t, double>    _mapPriceByDate;
        bool                        _isObjValid;

        size_t  checkDateFormat(std::string const& date);

        void    checkCSVHeader(std::string const& line);
        void    checkCSVLine(std::string const& line);

        void    checkInputHeader(std::string const& line);
        void    checkInputLine(std::string const& line);

        double  getExactOrNearestPastPrice(size_t date);

    public:
        BitcoinExchange();
        BitcoinExchange(std::string const& filename);
        BitcoinExchange(BitcoinExchange const& rhs);
        ~BitcoinExchange();
        BitcoinExchange&    operator=(BitcoinExchange const& rhs);

        bool                                isValid() const;
        std::map<size_t, double> const&     getMapPriceByDate() const;

        void    readDB(std::ifstream& dbfile);
        void    analyze(std::ifstream& infile);

};

#endif