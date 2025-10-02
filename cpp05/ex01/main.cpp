/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:53:09 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/12 17:22:16 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Project Header
#include "Bureaucrat.hpp"
#include "Form.hpp"

// CPP Header
#include <iostream>

int main()
{
    Bureaucrat  unknown("Unknown", 1);
    Form        fDefault;
    Form        f1("Outside #1", 100, 98);

    // Deep Copy
    std::cout << std::endl;
    std::cout << "======= DEEP COPY =========" << std::endl;
    {
        Form    fd1(f1);
        Form    fd2("Insider #1", 50, 40);

        fd2 = f1;

        std::cout << std::endl;
        std::cout << "=== BEFORE ===" << std::endl;
        std::cout << "Original: " << f1 << std::endl;
        std::cout << "Clone: " << fd1 << std::endl;
        std::cout << "Copy: " << fd2 << std::endl;
        std::cout << std::endl;

        unknown.signForm(fd1);

        std::cout << "=== AFTER ===" << std::endl;
        std::cout << "Original: " << f1 << std::endl;
        std::cout << "Clone: " << fd1 << std::endl;
        std::cout << "Copy: " << fd2 << std::endl;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Original: " << f1 << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << std::endl;

    // Too Low Create
    std::cout << "======== CREATE EXCEPTION ========" << std::endl;
    try
    {
        Form    flow1("Too Low #1", 151, 50);

        std::cout << "(This line won't show) " << flow1 << std::endl;
    }
    catch (std::exception const& e)
    {
        std::cout << "[Too low sign grade]: " << e.what() << std::endl;
    }
    try
    {
        Form    flow1("Too Low #2", 15, 151);

        std::cout << "(This line won't show) " << flow1 << std::endl;
    }
    catch (std::exception const& e)
    {
        std::cout << "[Too low execute grade]: " << e.what() << std::endl;
    }

    // Too High Create
    try
    {
        Form    fhigh1("Too Low #1", 0, 50);

        std::cout << "(This line won't show) " << fhigh1 << std::endl;
    }
    catch (std::exception const& e)
    {
        std::cout << "[Too high sign grade]: " << e.what() << std::endl;
    }
    try
    {
        Form    fhigh1("Too Low #2", 15, 0);

        std::cout << "(This line won't show) " << fhigh1 << std::endl;
    }
    catch (std::exception const& e)
    {
        std::cout << "[Too high execute grade]: " << e.what() << std::endl;
    }
    std::cout << "==================================" << std::endl;
    std::cout << std::endl;

    // Sign
    std::cout << "======== SIGN FORM ========" << std::endl;

    Bureaucrat  b1("John Doe", 1);
    Bureaucrat  b2("Jane Doe", 150);

    std::cout << std::endl;
    std::cout << "Before: " << f1 << std::endl;
    std::cout << std::endl;

    b2.signForm(f1);
    b1.signForm(f1);
    b1.signForm(f1);

    std::cout << std::endl;
    std::cout << "After: " << f1 << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << std::endl;

    return 0;
}