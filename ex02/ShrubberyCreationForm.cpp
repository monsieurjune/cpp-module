/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:08:18 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/10 16:52:45 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Project Header
#include "ShrubberyCreationForm.hpp"

// CPP Header
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
                            : AForm(
                                __SHRUBBERY_CREATION_FORM_DEFAULT_NAME__,
                                __SHRUBBERY_CREATION_FORM_SIGN_GRADE__,
                                __SHRUBBERY_CREATION_FORM_EXECUTE_GRADE__
                            )
{
    std::cout << "Shruberry Creation Form <" << this->getName() << "> (" 
                << this->getSignGradeThreshold() << "," << this->getExecuteGradeThreshold() 
                << ") (" << (this->getIsSigned() ? "signed" : "unsigned") 
                << ") is created from default constructor program" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
                            : AForm(
                                target,
                                __SHRUBBERY_CREATION_FORM_SIGN_GRADE__,
                                __SHRUBBERY_CREATION_FORM_EXECUTE_GRADE__
                            )
{
    std::cout << "Shruberry Creation Form <" << this->getName() << "> (" 
                << this->getSignGradeThreshold() << "," << this->getExecuteGradeThreshold() 
                << ") (" << (this->getIsSigned() ? "signed" : "unsigned") 
                << ") is created from default constructor program" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& obj) : AForm(obj)
{
    std::cout << "Shruberry Creation Form <" << this->getName() << "> (" 
            << this->getSignGradeThreshold() << "," << this->getExecuteGradeThreshold() 
            << ") (" << (this->getIsSigned() ? "signed" : "unsigned") 
            << ") is copied" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Shruberry Creation Form <" << this->getName() << "> (" 
            << this->getSignGradeThreshold() << "," << this->getExecuteGradeThreshold() 
            << ") (" << (this->getIsSigned() ? "signed" : "unsigned") 
            << ") is discarded" << std::endl;
}

ShrubberyCreationForm   ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs)
{
    std::cout << "Copy Signature of Shruberry Creation Form <" 
                << rhs.getName() << "> (" << rhs.getSignGradeThreshold() 
                << "," << rhs.getExecuteGradeThreshold() 
                << ") (" << (rhs.getIsSigned() ? "signed" : "unsigned") 
                << ") to Form <" << this->getName() << "> (" 
                << this->getSignGradeThreshold() << "," << this->getExecuteGradeThreshold() 
                << ") (" << (this->getIsSigned() ? "signed" : "unsigned") << ")" << std::endl;

    AForm::operator=(rhs);

    return *this;
}

void    ShrubberyCreationForm::execute(Bureaucrat const& executor) const
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

    // execute
    std::ofstream   shrubbery(
                        this->getName() + "_shrubbery", 
                        std::ios::out | std::ios::trunc
                    );

    if (!shrubbery)
    {
        throw AForm::ExecutionFailedException(
                    "Can\'t open " + this->getName() + "_shrubbery"
                );
    }

    // create ascii tree (no throw when error)
    shrubbery << "          &&& &&  & &&" << std::endl;
    shrubbery << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
    shrubbery << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
    shrubbery << "   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
    shrubbery << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
    shrubbery << "&&   && & &| &| /& & % ()& /&&" << std::endl;
    shrubbery << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
    shrubbery << "     &&     \\|||" << std::endl;
    shrubbery << "             |||" << std::endl;
    shrubbery << "             |||" << std::endl;
    shrubbery << "             |||" << std::endl;
    shrubbery << "       , -=-~  .-^- _" << std::endl;
    shrubbery << "ejm97         `" << std::endl;

    // check fail & bad bits
    if (shrubbery.fail())
    {
        shrubbery.close();
        throw AForm::ExecutionFailedException(
                "IO Error occured when writing " + this->getName() + "_shrubbery"
            );
    }

    // close file
    shrubbery.close();
}