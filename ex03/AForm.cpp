/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:36:37 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/16 19:53:14 by tponutha         ###   ########.fr       */
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
        throw AForm::GradeTooLowException("Form's sign grade is too low");
    }
}

static inline void  sb_check_sign_grade_too_high(int grade)
{
    if (grade < __FORM_HIGHEST_GRADE__)
    {
        throw AForm::GradeTooHighException("Form's sign grade is too high");
    }
}

static inline void  sb_check_execute_grade_too_low(int grade)
{
    if (grade > __FORM_LOWEST_GRADE__)
    {
        throw AForm::GradeTooLowException("Form's execute grade is too low");
    }
}

static inline void  sb_check_execute_grade_too_high(int grade)
{
    if (grade < __FORM_HIGHEST_GRADE__)
    {
        throw AForm::GradeTooHighException("Form's execute grade is too high");
    }
}

// Orthodox

AForm::AForm() : _name(__FORM_DEFAULT_NAME__), \
                    _target(__FORM_DEFAULT_NAME__), \
                    _isSigned(false), \
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

    // log
    std::cout << _name << " <" << _target << "> (" 
                << _signGradeThreshold << "," << _executeGradeThreshold
                << ") (" << (_isSigned ? "signed" : "unsigned") 
                << ") is created from default constructor" 
                << std::endl;
}

AForm::AForm(std::string const& name, std::string const& target, int const signGrade, int const executeGrade)
                : _name(name), \
                _target(target), \
                _isSigned(false), \
                _signGradeThreshold(signGrade), \
                _executeGradeThreshold(executeGrade)
{
    // sign
    sb_check_sign_grade_too_low(_signGradeThreshold);
    sb_check_sign_grade_too_high(_signGradeThreshold);
    
    // execute
    sb_check_execute_grade_too_low(_executeGradeThreshold);
    sb_check_execute_grade_too_high(_executeGradeThreshold);

    // log
    std::cout << _name << " <" << _target << "> (" 
                << _signGradeThreshold << "," << _executeGradeThreshold
                << ") (" << (_isSigned ? "signed" : "unsigned") 
                << ") is created from constructor" 
                << std::endl;
}

AForm::AForm(AForm const& obj) : _name(obj.getName()), \
                                    _target(obj.getTarget()), \
                                    _isSigned(obj.getIsSigned()), \
                                    _signGradeThreshold(obj.getSignGradeThreshold()), \
                                    _executeGradeThreshold(obj.getExecuteGradeThreshold())
{
    // log
    std::cout << _name << " <" << _target << "> (" 
                << _signGradeThreshold << "," << _executeGradeThreshold
                << ") (" << (_isSigned ? "signed" : "unsigned")
                << ") is copied" 
                << std::endl;
}

AForm::~AForm()
{
    // log
    std::cout << _name << " <" << _target << "> (" 
                << _signGradeThreshold << "," << _executeGradeThreshold
                << ") (" << (_isSigned ? "signed" : "unsigned") 
                << ") is discard" 
                << std::endl;
}

AForm&  AForm::operator=(AForm const& rhs)
{
    // log
    std::cout << rhs.getName() << " <" << rhs.getTarget() << "> ("
                << rhs.getSignGradeThreshold() << rhs.getExecuteGradeThreshold()
                << ") (" << (rhs.getIsSigned() ? "signed" : "unsigned") << ")"
                << " -> " << _name << " <" << _target << "> ("
                << _signGradeThreshold << "," << _executeGradeThreshold
                << ") (" << (_isSigned ? "signed" : "unsigned") << ")"
                << std::endl;

    // assign
    _isSigned = rhs.getIsSigned();

    return *this;
}

// Getter

std::string const&  AForm::getName() const
{
    return _name;
}

std::string const&  AForm::getTarget() const
{
    return _target;
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

void    AForm::beSigned(Bureaucrat const& signer)
{
    if (_isSigned)
    {
        return;
    }

    if (signer.getGrade() > _signGradeThreshold)
    {
        throw AForm::GradeTooLowException("Signer's grade is too low");
    }

    _isSigned = true;
}

// Exception

AForm::GradeTooHighException::GradeTooHighException(std::string const& msg) : BaseBureaucraticException(msg) {}

AForm::GradeTooLowException::GradeTooLowException(std::string const& msg) : BaseBureaucraticException(msg) {}

AForm::ExecutionFailedException::ExecutionFailedException(std::string const& msg) : BaseBureaucraticException(msg) {}

AForm::UnsignedFormException::UnsignedFormException() : BaseBureaucraticException("This form is unsigned") {}

// ostream

std::ostream&   operator<<(std::ostream& out, AForm const& rhs)
{
    out << rhs.getName() << " <" << rhs.getTarget() << ">"
        << ", form grade (" << rhs.getSignGradeThreshold() << "," 
        << rhs.getExecuteGradeThreshold() << ") (" 
        << (rhs.getIsSigned() ? "signed" : "unsigned") << ")";

    return out;
}