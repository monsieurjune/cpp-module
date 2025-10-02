/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:08:18 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/16 20:02:31 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Project Header
#include "ShrubberyCreationForm.hpp"

// CPP Header
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
                            : AForm(
                                __SHRUBBERY_CREATION_FORM_NAME__,
                                __SHRUBBERY_CREATION_FORM_DEFAULT_TARGET__,
                                __SHRUBBERY_CREATION_FORM_SIGN_GRADE__,
                                __SHRUBBERY_CREATION_FORM_EXECUTE_GRADE__
                            )
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
                            : AForm(
                                __SHRUBBERY_CREATION_FORM_NAME__,
                                target,
                                __SHRUBBERY_CREATION_FORM_SIGN_GRADE__,
                                __SHRUBBERY_CREATION_FORM_EXECUTE_GRADE__
                            )
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& obj) : AForm(obj)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm   ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs)
{
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