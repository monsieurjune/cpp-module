/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:07:57 by tponutha          #+#    #+#             */
/*   Updated: 2025/04/04 14:29:45 by tponutha         ###   ########.fr       */
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
                            __ROBOTOMY_REQUEST_FORM_DEFAULT_NAME__,
                            __ROBOTOMY_REQUEST_FORM_SIGN_GRADE__,
                            __ROBOTOMY_REQUEST_FORM_EXECUTE_GRADE__
                        )
{
    std::cout << "Robotomy Request Form <" << this->getName() << "> (" 
                << this->getSignGradeThreshold() << "," << this->getExecuteGradeThreshold() 
                << ") (" << (this->getIsSigned() ? "signed" : "unsigned") 
                << ") is created from default constructor program" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
                        : AForm(
                            __ROBOTOMY_REQUEST_FORM_DEFAULT_NAME__,
                            __ROBOTOMY_REQUEST_FORM_SIGN_GRADE__,
                            __ROBOTOMY_REQUEST_FORM_EXECUTE_GRADE__
                        )
{
    std::cout << "Robotomy Request Form <" << this->getName() << "> (" 
            << this->getSignGradeThreshold() << "," << this->getExecuteGradeThreshold() 
            << ") (" << (this->getIsSigned() ? "signed" : "unsigned") 
            << ") is created from constructor program" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& obj) : AForm(obj)
{
    std::cout << "Robotomy Request Form <" << this->getName() << "> (" 
            << this->getSignGradeThreshold() << "," << this->getExecuteGradeThreshold() 
            << ") (" << (this->getIsSigned() ? "signed" : "unsigned") 
            << ") is copied" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Robotomy Request Form <" << this->getName() << "> (" 
            << this->getSignGradeThreshold() << "," << this->getExecuteGradeThreshold() 
            << ") (" << (this->getIsSigned() ? "signed" : "unsigned") 
            << ") is discarded" << std::endl;
}

RobotomyRequestForm&    RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs)
{
    std::cout << "Copy Signature of Presidential Pardon Form <" 
                << rhs.getName() << "> (" << rhs.getSignGradeThreshold() 
                << "," << rhs.getExecuteGradeThreshold() 
                << ") (" << (rhs.getIsSigned() ? "signed" : "unsigned") 
                << ") to Form <" << this->getName() << "> (" 
                << this->getSignGradeThreshold() << "," << this->getExecuteGradeThreshold() 
                << ") (" << (this->getIsSigned() ? "signed" : "unsigned") << ")" << std::endl;

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
        throw AForm::GradeTooLowException("execute");
    }

    std::srand(std::time(NULL));
    if (std::rand() % 2)
    {
        throw AForm::ExecutionFailedException("the robotomy failed");
    }

    std::cout << "b.r..r.zzz.zz...." << std::endl;
    std::cout << "B.r.R..zzZ..ZZ.." << std::endl;
    std::cout << "BBRRRRZZZZ......" << std::endl;
    std::cout << this->getName() << " has been robotomized successfully 50% of the time" << std::endl;
}