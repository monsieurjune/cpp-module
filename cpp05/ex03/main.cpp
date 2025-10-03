/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:53:09 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/16 21:13:54 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Project Header
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

// CPP Header
#include <iostream>

int main()
{
    std::cout << "===== Create Intern & Form =====" << std::endl;
    Intern  intern0;
    AForm*  form_president_1 = intern0.makeForm(__PRESIDENTIAL_PARDON_FORM_NAME__, "brr brr patapim");
    AForm*  form_robotomy_1 = intern0.makeForm(__ROBOTOMY_REQUEST_FORM_NAME__, "Sacred Servitor");
    AForm*  form_shruberry_1 = intern0.makeForm(__SHRUBBERY_CREATION_FORM_NAME__, "Tree at backyard");
    AForm*  form_nan = intern0.makeForm("jnjnvsdipvmsd", "jcddcmsm,c");

    // 100% NULL
    std::cout << "100% NULL: " << form_nan << std::endl;

    // Just in case
    if (!form_president_1 || !form_robotomy_1 || !form_shruberry_1)
    {
        delete form_president_1;
        delete form_robotomy_1;
        delete form_shruberry_1;
        return 0;
    }

    std::cout << std::endl;
    std::cout << "===== Create Bureuacrats =====" << std::endl;
    Bureaucrat  b0("Super Entities", __FORM_HIGHEST_GRADE__);
    Bureaucrat  b1("Trainee", __FORM_LOWEST_GRADE__);
    Bureaucrat  b2("Vice President", __PRESIDENTIAL_PARDON_FORM_SIGN_GRADE__);
    Bureaucrat  b3("Techpreist", __ROBOTOMY_REQUEST_FORM_SIGN_GRADE__);
    Bureaucrat  b4("Gardener", __SHRUBBERY_CREATION_FORM_SIGN_GRADE__);

    // Test Can't sign & execute
    std::cout << std::endl;
    std::cout << "======= TEST =========" << std::endl;
    b1.signForm(*form_shruberry_1);
    b1.signForm(*form_robotomy_1);
    b1.signForm(*form_president_1);
    b1.executeForm(*form_shruberry_1);
    b1.executeForm(*form_robotomy_1);
    b1.executeForm(*form_president_1);

    // Shurrubery
    std::cout << std::endl;
    std::cout << "======= SHRUBERRY =========" << std::endl;
    std::cout << "Before Sign: " << *form_shruberry_1 << std::endl;
    b4.signForm(*form_shruberry_1);
    std::cout << "After Sign: " << *form_shruberry_1 << std::endl;
    b4.executeForm(*form_shruberry_1);
    b0.executeForm(*form_shruberry_1);

    // Robotomy
    std::cout << std::endl;
    std::cout << "======= ROBOTOMY =========" << std::endl;
    std::cout << "Before Sign: " << *form_robotomy_1 << std::endl;
    b3.signForm(*form_robotomy_1);
    std::cout << "After Sign: " << *form_robotomy_1 << std::endl;
    b4.executeForm(*form_robotomy_1);
    b0.executeForm(*form_robotomy_1);

    // President
    std::cout << std::endl;
    std::cout << "======= PRESIDENT =========" << std::endl;
    std::cout << "Before Sign: " << *form_president_1 << std::endl;
    b2.signForm(*form_president_1);
    std::cout << "After Sign: " << *form_president_1 << std::endl;
    b4.executeForm(*form_president_1);
    b0.executeForm(*form_president_1);

    // Deconstructor
    std::cout << std::endl;
    std::cout << "======= DESTROY =========" << std::endl;
    delete form_president_1;
    delete form_robotomy_1;
    delete form_shruberry_1;

    return 0;
}