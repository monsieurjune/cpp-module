/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:53:09 by tponutha          #+#    #+#             */
/*   Updated: 2025/04/02 12:11:41 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Project Header
#include "Bureaucrat.hpp"

// CPP Header
#include <iostream>

int main()
{
    Bureaucrat  b0("Example One", 100);
    Bureaucrat  bDefault;

    // Deep Copy
    std::cout << "======= DEEP COPY =========" << std::endl;
    {
        Bureaucrat  bd1(b0);
        Bureaucrat  bd2("Example Two", 11);
        
        bd2 = b0;

        std::cout << std::endl;
        std::cout << "Original: " << b0 << std::endl;
        std::cout << "Clone: " << bd1 << std::endl;
        std::cout << "Copy: " << bd2 << std::endl;

        bd1.incrementGrade();
        bd2.decrementGrade();

        std::cout << std::endl;
        std::cout << "Original: " << b0 << std::endl;
        std::cout << "Clone: " << bd1 << std::endl;
        std::cout << "Copy: " << bd2 << std::endl;
        std::cout << std::endl;
    }
    std::cout << "Original: " << b0 << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << std::endl;

    // Create Exception
    std::cout << "======== CREATE EXCEPTION ========" << std::endl;

    // Too Low
    try
    {
        Bureaucrat  blow("Too Low", 132231);

        std::cout << "(This line won't show) " << blow << std::endl;
    }
    catch (std::exception const& e)
    {
        std::cout << "[ERROR]: " << e.what() << std::endl;
    }

    // Too High
    try
    {
        Bureaucrat  bhigh("Too High", 0);

        std::cout << "(This line won't show) " << bhigh << std::endl;
    }
    catch (std::exception const& e)
    {
        std::cout << "[ERROR]: " << e.what() << std::endl;
    }
    std::cout << "==================================" << std::endl;
    std::cout << std::endl;

    // Grade Exception
    std::cout << "======== GRADE EXCEPTION ========" << std::endl;

    // Too Low
    Bureaucrat  john("John Doe", 148);

    try
    {
        std::cout << john << std::endl;
        john.decrementGrade();
        std::cout << john << std::endl;
        john.decrementGrade();
        std::cout << john << std::endl;
        john.decrementGrade();
        std::cout << john << std::endl;
    }
    catch (std::exception const& e)
    {
        std::cout << "[ERROR]: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Too High
    Bureaucrat  jane("Jane Dae", 3);

    try
    {
        std::cout << jane << std::endl;
        jane.incrementGrade();
        std::cout << jane << std::endl;
        jane.incrementGrade();
        std::cout << jane << std::endl;
        jane.incrementGrade();
        std::cout << jane << std::endl;
    }
    catch (std::exception const& e)
    {
        std::cout << "[ERROR]: " << e.what() << std::endl;
    }
    std::cout << "==================================" << std::endl;
    std::cout << std::endl;

    // Great Promote
    std::cout << "======== BEFORE PROMOTION ========" << std::endl;
    std::cout << "Before Promotion: " << john << std::endl;
    for (int i = 0; i < 200; i++)
    {
        try
        {
            john.incrementGrade();
        }
        catch (std::exception const& e)
        {
            break;
        }
    }
    std::cout << "After Promotion: " << john << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << std::endl;

    // Greate Demote
    std::cout << "======== BEFORE DEMOTION ========" << std::endl;
    std::cout << "Before Demotion: " << jane << std::endl;
    for (int i = 0; i < 200; i++)
    {
        try
        {
            jane.decrementGrade();
        }
        catch (std::exception const& e)
        {
            break;
        }
    }
    std::cout << "After Demotion: " << jane << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << std::endl;

    return 0;
}