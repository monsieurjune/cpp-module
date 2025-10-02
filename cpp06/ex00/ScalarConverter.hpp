/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:45:53 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/28 15:44:18 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALAR_CONVERTER_HPP__
#define __SCALAR_CONVERTER_HPP__
#include <string>

class ScalarConverter
{
    private:
        ScalarConverter();

    public:
        static void convert(std::string const& str);
};

#endif