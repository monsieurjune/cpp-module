/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:08:18 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/15 08:52:44 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Project Header
#include "ShrubberyCreationForm.hpp"

// CPP Header
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
                            : AForm(
                                "ShrubberyCreationForm",
                                __SHRUBBERY_CREATION_FORM_DEFAULT_NAME__,
                                __SHRUBBERY_CREATION_FORM_SIGN_GRADE__,
                                __SHRUBBERY_CREATION_FORM_EXECUTE_GRADE__
                            )
{
    std::cout << "Shruberry Creation Form <" << this->getTarget() << "> (" 
                << this->getSignGradeThreshold() << "," << this->getExecuteGradeThreshold() 
                << ") (" << (this->getIsSigned() ? "signed" : "unsigned") 
                << ") is created from default constructor program" 
                << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
                            : AForm(
                                "ShrubberyCreationForm",
                                target,
                                __SHRUBBERY_CREATION_FORM_SIGN_GRADE__,
                                __SHRUBBERY_CREATION_FORM_EXECUTE_GRADE__
                            )
{
    std::cout << "Shruberry Creation Form <" << this->getTarget() << "> (" 
                << this->getSignGradeThreshold() << "," << this->getExecuteGradeThreshold() 
                << ") (" << (this->getIsSigned() ? "signed" : "unsigned") 
                << ") is created from default constructor program" 
                << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& obj) : AForm(obj)
{
    std::cout << "Shruberry Creation Form <" << this->getTarget() << "> (" 
            << this->getSignGradeThreshold() << "," << this->getExecuteGradeThreshold() 
            << ") (" << (this->getIsSigned() ? "signed" : "unsigned") 
            << ") is copied"
            << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Shruberry Creation Form <" << this->getTarget() << "> (" 
            << this->getSignGradeThreshold() << "," << this->getExecuteGradeThreshold() 
            << ") (" << (this->getIsSigned() ? "signed" : "unsigned") 
            << ") is discarded" 
            << std::endl;
}

ShrubberyCreationForm   ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs)
{
    std::cout << "Copy Signature of Shruberry Creation Form <" 
                << rhs.getTarget() << "> (" << rhs.getSignGradeThreshold() 
                << "," << rhs.getExecuteGradeThreshold() 
                << ") (" << (rhs.getIsSigned() ? "signed" : "unsigned") 
                << ") to Form <" << this->getTarget() << "> (" 
                << this->getSignGradeThreshold() << "," << this->getExecuteGradeThreshold() 
                << ") (" << (this->getIsSigned() ? "signed" : "unsigned") << ")" 
                << std::endl;

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
        throw Bureaucrat::GradeTooLowException();
    }

    // execute
    std::string     name = this->getTarget() + "_shrubbery";
    std::ofstream   shrubbery(
                        name.c_str(), 
                        std::ios_base::out | std::ios_base::trunc
                    );

    if (!shrubbery)
    {
        throw AForm::ExecutionFailedException(
                    "Can\'t open " + this->getTarget() + "_shrubbery"
                );
    }

    // create ascii tree (no throw when error)
    shrubbery << "          &&& &&  & &&"           << std::endl;
    shrubbery << "      && &\\/&\\|& ()|/ @, &&"    << std::endl;
    shrubbery << "      &\\/(/&/&||/& /_/)_&/_&"    << std::endl;
    shrubbery << "   &() &\\/&|()|/&\\/ '%\" & ()"  << std::endl;
    shrubbery << "  &_\\_&&_\\ |& |&&/&__%_/_& &&"  << std::endl;
    shrubbery << "&&   && & &| &| /& & % ()& /&&"   << std::endl;
    shrubbery << " ()&_---()&\\&\\|&&-&&--%---()~"  << std::endl;
    shrubbery << "     &&     \\|||"                << std::endl;
    shrubbery << "             |||"                 << std::endl;
    shrubbery << "             |||"                 << std::endl;
    shrubbery << "             |||"                 << std::endl;
    shrubbery << "       , -=-~  .-^- _"            << std::endl;
    shrubbery << "ejm97         `"                  << std::endl;

    // check fail & bad bits
    if (shrubbery.fail())
    {
        shrubbery.close();
        throw AForm::ExecutionFailedException(
                "IO Error occured when writing " + this->getTarget() + "_shrubbery"
            );
    }

    // close file
    shrubbery.close();
}