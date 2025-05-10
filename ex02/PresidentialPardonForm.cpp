/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:07:54 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/10 22:01:03 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Project Header
#include "PresidentialPardonForm.hpp"

// CPP Header
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
                            : AForm(
                                    __PRESIDENTIAL_PARDON_FORM_DEFAULT_NAME__,
                                    __PRESIDENTIAL_PARDON_FORM_SIGN_GRADE__,
                                    __PRESIDENTIAL_PARDON_FORM_EXECUTE_GRADE__
                                )
{
    std::cout << "Presidential Pardon Form <" << this->getName() << "> (" 
                << this->getSignGradeThreshold() << "," << this->getExecuteGradeThreshold() 
                << ") (" << (this->getIsSigned() ? "signed" : "unsigned") 
                << ") is created from default constructor program" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
                            : AForm(
                                    target,
                                    __PRESIDENTIAL_PARDON_FORM_SIGN_GRADE__,
                                    __PRESIDENTIAL_PARDON_FORM_EXECUTE_GRADE__
                                )
{
    std::cout << "Presidential Pardon Form <" << this->getName() << "> (" 
                << this->getSignGradeThreshold() << "," << this->getExecuteGradeThreshold() 
                << ") (" << (this->getIsSigned() ? "signed" : "unsigned") 
                << ") is created from default constructor program" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& obj) : AForm(obj)
{
    std::cout << "Presidential Pardon Form <" << this->getName() << "> (" 
            << this->getSignGradeThreshold() << "," << this->getExecuteGradeThreshold() 
            << ") (" << (this->getIsSigned() ? "signed" : "unsigned") 
            << ") is copied" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Presidential Pardon Form <" << this->getName() << "> (" 
            << this->getSignGradeThreshold() << "," << this->getExecuteGradeThreshold() 
            << ") (" << (this->getIsSigned() ? "signed" : "unsigned") 
            << ") is discarded" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs)
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

void    PresidentialPardonForm::execute(Bureaucrat const& executor) const
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

    std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}