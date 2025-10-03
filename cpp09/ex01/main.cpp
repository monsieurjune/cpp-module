/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:52:22 by tponutha          #+#    #+#             */
/*   Updated: 2025/06/16 18:45:20 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

int main(const int argc, const char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    // the rest
    std::string         buff;
    std::stringstream   ss(argv[1]);
    RPN                 rpn;

    try
    {
        while (std::getline(ss, buff, ' '))
        {
            if (buff.empty())
            {
                continue;
            }

            rpn.add(buff);
        }
        std::cout << rpn.ans() << std::endl;
    }
    catch (std::runtime_error const& e)
    {
        std::cerr << "Error" << std::endl;
    }
    catch (std::logic_error const& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (std::exception const& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}