/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:36:37 by tponutha          #+#    #+#             */
/*   Updated: 2025/04/03 11:28:58 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Project Header
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// CPP Header
#include <iostream>

// Helper

static inline void  sb_check_sign_grade_too_low(int grade)
{
    if (grade > __FORM_LOWEST_GRADE__)
    {
        throw AForm::GradeTooLowException("sign");
    }
}

static inline void  sb_check_sign_grade_too_high(int grade)
{
    if (grade < __FORM_HIGHEST_GRADE__)
    {
        throw AForm::GradeTooHighException("sign");
    }
}

static inline void  sb_check_execute_grade_too_low(int grade)
{
    if (grade > __FORM_LOWEST_GRADE__)
    {
        throw AForm::GradeTooLowException("execute");
    }
}

static inline void  sb_check_execute_grade_too_high(int grade)
{
    if (grade < __FORM_HIGHEST_GRADE__)
    {
        throw AForm::GradeTooHighException("execute");
    }
}

// Orthodox

AForm::AForm() : _name(__FORM_DEFAULT_NAME__), \
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
}

AForm::AForm(std::string const& name, int const signGrade, int const executeGrade)
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
}

AForm::AForm(AForm const& obj) : _name(obj.getName()), \
                                    _isSigned(obj.getIsSigned()), \
                                    _signGradeThreshold(obj.getSignGradeThreshold()), \
                                    _executeGradeThreshold(obj.getExecuteGradeThreshold())
{
    // nothing
}

AForm::~AForm() {}

AForm&  AForm::operator=(AForm const& rhs)
{
    _isSigned = rhs.getIsSigned();

    return *this;
}

// Getter

std::string const&  AForm::getName() const
{
    return _name;
}

bool    AForm::getIsSigned() const
{
    return _isSigned;
}

int AForm::getSignGradeThreshold() const
{
    return _signGradeThreshold;
}

int AForm::getExecuteGradeThreshold() const
{
    return _executeGradeThreshold;
}

// Sign

bool    AForm::beSigned(Bureaucrat const& signer)
{
    if (_isSigned)
    {
        return false;
    }

    if (signer.getGrade() > _signGradeThreshold)
    {
        throw AForm::GradeTooLowException("sign");
    }

    _isSigned = true;

    return true;
}

// Exception

AForm::GradeTooHighException::GradeTooHighException(const char* grade_type)
        : BaseBureaucraticException(
            std::string("Form's ") +
            std::string(grade_type) + 
            std::string(" grade is too high")
        ) {}

AForm::GradeTooLowException::GradeTooLowException(const char* grade_type)
        : BaseBureaucraticException(
            std::string("Form's ") +
            std::string(grade_type) + 
            std::string(" grade is too low")
        ) {}

// ostream

std::ostream&   operator<<(std::ostream& out, AForm const& rhs)
{
    out << rhs.getName() << ", form grade (" 
        << rhs.getSignGradeThreshold() << "," 
        << rhs.getExecuteGradeThreshold() << ") (" 
        << (rhs.getIsSigned() ? "signed" : "unsigned") << ")";

    return out;
}