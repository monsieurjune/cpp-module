/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:07:54 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/16 19:58:43 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Project Header
#include "PresidentialPardonForm.hpp"

// CPP Header
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
                            : AForm(
                                    __PRESIDENTIAL_PARDON_FORM_NAME__,
                                    __PRESIDENTIAL_PARDON_FORM_DEFAULT_TARGET__,
                                    __PRESIDENTIAL_PARDON_FORM_SIGN_GRADE__,
                                    __PRESIDENTIAL_PARDON_FORM_EXECUTE_GRADE__
                                )
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
                            : AForm(
                                    __PRESIDENTIAL_PARDON_FORM_NAME__,
                                    target,
                                    __PRESIDENTIAL_PARDON_FORM_SIGN_GRADE__,
                                    __PRESIDENTIAL_PARDON_FORM_EXECUTE_GRADE__
                                )
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& obj) : AForm(obj)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs)
{
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

    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}