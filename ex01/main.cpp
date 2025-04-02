/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:53:09 by tponutha          #+#    #+#             */
/*   Updated: 2025/04/02 15:01:10 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Project Header
#include "Bureaucrat.hpp"
#include "Form.hpp"

// CPP Header
#include <iostream>

int main()
{
    Form    fDefault;
    Form    f1("Outside #1", 100, 98);

    // Deep Copy
    std::cout << "======= DEEP COPY =========" << std::endl;
    {
        Form    fd1(f1);
        Form    fd2("Insider #1", 50, 40);

        fd2 = f1;

        std::cout << std::endl;
        std::cout << "Original: " << f1 << std::endl;
        std::cout << "Clone: " << fd1 << std::endl;
        std::cout << "Copy: " << fd2 << std::endl;
    }
    std::cout << "Original: " << f1 << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << std::endl;

    return 0;
}