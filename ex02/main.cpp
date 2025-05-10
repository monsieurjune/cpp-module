/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:53:09 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/10 22:54:13 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Project Header
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// CPP Header
#include <iostream>

int main()
{
    std::cout << "Create Bureuacrats" << std::endl;
    Bureaucrat  b0("Super Entities", __FORM_HIGHEST_GRADE__);
    Bureaucrat  b1("Trainee", __FORM_LOWEST_GRADE__);
    Bureaucrat  b2("Vice President", __PRESIDENTIAL_PARDON_FORM_SIGN_GRADE__);
    Bureaucrat  b3("Techpreist", __ROBOTOMY_REQUEST_FORM_SIGN_GRADE__);
    Bureaucrat  b4("Gardener", __SHRUBBERY_CREATION_FORM_SIGN_GRADE__);

    std::cout << std::endl;
    std::cout << "Create Form" << std::endl;
    PresidentialPardonForm  form_president_1("Unknown Person");
    RobotomyRequestForm     form_robotomy_1("Servitor");
    ShrubberyCreationForm   form_shruberry_1("Bonzai");

    // Deep Copy
    std::cout << std::endl;
    std::cout << "======= DEEP COPY =========" << std::endl;
    {
        // Since All of Object use same method of copy
        PresidentialPardonForm  copied_form_0 = form_president_1;
        RobotomyRequestForm     copied_form_1 = RobotomyRequestForm(form_robotomy_1);

        // Sign Form
        b0.signForm(copied_form_0);
        b0.signForm(copied_form_1);

        std::cout << "COPIED: " << copied_form_0 << std::endl;
        std::cout << "ORIGINAL: " << form_president_1 << std::endl;
        std::cout << "COPIED: " << copied_form_1 << std::endl;
        std::cout << "ORIGINAL: " << form_robotomy_1 << std::endl;
    }

    // Test Can't sign & execute
    std::cout << std::endl;
    std::cout << "======= TEST =========" << std::endl;
    b1.signForm(form_shruberry_1);
    b1.signForm(form_robotomy_1);
    b1.signForm(form_president_1);
    b1.executeForm(form_shruberry_1);
    b1.executeForm(form_robotomy_1);
    b1.executeForm(form_president_1);

    // Shurrubery
    std::cout << std::endl;
    std::cout << "======= SHRUBERRY =========" << std::endl;
    std::cout << "Before Sign: " << form_shruberry_1 << std::endl;
    b4.signForm(form_shruberry_1);
    std::cout << "After Sign: " << form_shruberry_1 << std::endl;
    b4.executeForm(form_shruberry_1);
    b0.executeForm(form_shruberry_1);

    // Robotomy
    std::cout << std::endl;
    std::cout << "======= ROBOTOMY =========" << std::endl;
    std::cout << "Before Sign: " << form_robotomy_1 << std::endl;
    b3.signForm(form_robotomy_1);
    std::cout << "After Sign: " << form_robotomy_1 << std::endl;
    b4.executeForm(form_robotomy_1);
    b0.executeForm(form_robotomy_1);

    // President
    std::cout << std::endl;
    std::cout << "======= PRESIDENT =========" << std::endl;
    std::cout << "Before Sign: " << form_president_1 << std::endl;
    b2.signForm(form_president_1);
    std::cout << "After Sign: " << form_president_1 << std::endl;
    b4.executeForm(form_president_1);
    b0.executeForm(form_president_1);

    // Deconstructor
    std::cout << std::endl;
    std::cout << "======= DESTROY =========" << std::endl;

    return 0;
}