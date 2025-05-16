/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:07:57 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/16 20:01:04 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Project Header
#include "RobotomyRequestForm.hpp"

// C Header
#include <ctime>
#include <cstdlib>

// CPP Header
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() 
                        : AForm(
                            __ROBOTOMY_REQUEST_FORM_NAME__,
                            __ROBOTOMY_REQUEST_FORM_DEFAULT_TARGET__,
                            __ROBOTOMY_REQUEST_FORM_SIGN_GRADE__,
                            __ROBOTOMY_REQUEST_FORM_EXECUTE_GRADE__
                        )
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
                        : AForm(
                            __ROBOTOMY_REQUEST_FORM_NAME__,
                            target,
                            __ROBOTOMY_REQUEST_FORM_SIGN_GRADE__,
                            __ROBOTOMY_REQUEST_FORM_EXECUTE_GRADE__
                        )
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& obj) : AForm(obj)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm&    RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs)
{
    AForm::operator=(rhs);

    return *this;
}

void    RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    // is sign yet
    if (!this->getIsSigned())
    {
        throw AForm::UnsignedFormException();
    }

    // lower in reverse way
    if (executor.getGrade() > this->getExecuteGradeThreshold())
    {
        throw Bureaucrat::GradeTooLowException();
    }

    // head & tail
    std::srand(std::time(NULL));
    if (std::rand() % 2)
    {
        throw AForm::ExecutionFailedException("the robotomy failed");
    }

    std::cout << "b.r..r.zzz.zz...." << std::endl;
    std::cout << "B.r.R..zzZ..ZZ.." << std::endl;
    std::cout << "BBRRRRZZZZ......" << std::endl;
    std::cout << this->getTarget() << " has been robotomized successfully 50% of the time" << std::endl;
}