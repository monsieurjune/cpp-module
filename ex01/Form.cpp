/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 06:07:44 by tponutha          #+#    #+#             */
/*   Updated: 2025/04/02 17:24:17 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Project Header
#include "Form.hpp"
#include "Bureaucrat.hpp"

// CPP Header
#include <iostream>

// Helper

static inline void  sb_check_sign_grade_too_low(int grade)
{
    if (grade > __FORM_LOWEST_GRADE__)
    {
        throw Form::GradeTooLowException("sign");
    }
}

static inline void  sb_check_sign_grade_too_high(int grade)
{
    if (grade < __FORM_HIGHEST_GRADE__)
    {
        throw Form::GradeTooHighException("sign");
    }
}

static inline void  sb_check_execute_grade_too_low(int grade)
{
    if (grade > __FORM_LOWEST_GRADE__)
    {
        throw Form::GradeTooLowException("execute");
    }
}

static inline void  sb_check_execute_grade_too_high(int grade)
{
    if (grade < __FORM_HIGHEST_GRADE__)
    {
        throw Form::GradeTooHighException("execute");
    }
}

// Orthodox

Form::Form() : _name(__FORM_DEFAULT_NAME__), \
                _signGradeThreshold(__FORM_DEFAULT_SIGN_GRADE__), \
                _executeGradeThreshold(__FORM_DEFAULT_EXECUTE_GRADE__)
{
    // In case of miss configuration
    // sign
    sb_check_sign_grade_too_low(_signGradeThreshold);
    sb_check_sign_grade_too_high(_signGradeThreshold);
    
    // execute
    sb_check_execute_grade_too_low(_executeGradeThreshold);
    sb_check_execute_grade_too_high(_executeGradeThreshold);

    std::cout << "Form <" << _name << "> (" 
                << _signGradeThreshold << "," << _executeGradeThreshold 
                << ") (" << (_isSigned ? "signed" : "unsigned") 
                << ") is created from default constructor program" << std::endl;
}

Form::Form(std::string const& name, int const signGrade, int const executeGrade)
                : _name(name), \
                _signGradeThreshold(signGrade), \
                _executeGradeThreshold(executeGrade)
{
    // sign
    sb_check_sign_grade_too_low(_signGradeThreshold);
    sb_check_sign_grade_too_high(_signGradeThreshold);
    
    // execute
    sb_check_execute_grade_too_low(_executeGradeThreshold);
    sb_check_execute_grade_too_high(_executeGradeThreshold);

    std::cout << "Form <" << _name << "> (" 
                << _signGradeThreshold << "," << _executeGradeThreshold 
                << ") (" << (_isSigned ? "signed" : "unsigned") 
                << ") is created from constructor program" << std::endl;
}

Form::Form(Form const& obj) : _name(obj.getName()), \
                                _isSigned(obj.getIsSigned()), \
                                _signGradeThreshold(obj.getSignGradeThreshold()), \
                                _executeGradeThreshold(obj.getExecuteGradeThreshold())
{
    std::cout << "Form <" << _name << "> (" 
                << _signGradeThreshold << "," << _executeGradeThreshold 
                << ") (" << (_isSigned ? "signed" : "unsigned") 
                << ") is copied" << std::endl;
}

Form::~Form()
{
    std::cout << "Form <" << _name << "> (" 
                << _signGradeThreshold << "," << _executeGradeThreshold 
                << ") (" << (_isSigned ? "signed" : "unsigned") 
                << ") is discarded" << std::endl;
}

Form&   Form::operator=(Form const& rhs)
{
    std::cout << "Copy Signature of Form <" << _name << "> (" 
                << _signGradeThreshold << "," << _executeGradeThreshold 
                << ") (" << (_isSigned ? "signed" : "unsigned") 
                << ") to Form <" << _name << "> (" 
                << _signGradeThreshold << "," << _executeGradeThreshold 
                << ") (" << (_isSigned ? "signed" : "unsigned") << ")" << std::endl;

    _isSigned = rhs.getIsSigned();

    return *this;
}

// Getter

std::string const&  Form::getName() const
{
    return _name;
}

bool    Form::getIsSigned() const
{
    return _isSigned;
}

int Form::getSignGradeThreshold() const
{
    return _signGradeThreshold;
}

int Form::getExecuteGradeThreshold() const
{
    return _executeGradeThreshold;
}

// Sign

bool    Form::beSigned(Bureaucrat const& signer)
{
    if (_isSigned)
    {
        return false;
    }

    if (signer.getGrade() > _signGradeThreshold)
    {
        throw Form::GradeTooLowException("sign");
    }

    _isSigned = true;
    
    return true;
}

// Exception

Form::GradeTooHighException::GradeTooHighException(const char* grade_type)
        : GradeOutOfBoundException(
            std::string("Form's ") +
            std::string(grade_type) + 
            std::string(" grade is too high")
        ) {}

Form::GradeTooLowException::GradeTooLowException(const char* grade_type)
        : GradeOutOfBoundException(
            std::string("Form's ") +
            std::string(grade_type) + 
            std::string(" grade is too low")
        ) {}

// ostream

std::ostream&   operator<<(std::ostream& out, Form const& rhs)
{
    out << rhs.getName() << ", form grade (" 
        << rhs.getSignGradeThreshold() << "," 
        << rhs.getExecuteGradeThreshold() << ") (" 
        << (rhs.getIsSigned() ? "signed" : "unsigned") << ")";

    return out;
}