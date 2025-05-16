/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:52:52 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/16 20:06:39 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Project Header
#include "Bureaucrat.hpp"
#include "Form.hpp"

// CPP Header
#include <iostream>

// Helper

static inline void  sb_check_grade_too_low(int grade)
{
    if (grade > __BUREAUCRAT_LOWEST_GRADE__)
    {
        throw Bureaucrat::GradeTooLowException();
    }
}

static inline void  sb_check_grade_too_high(int grade)
{
    if (grade < __BUREAUCRAT_HIGHEST_GRADE__)
    {
        throw Bureaucrat::GradeTooHighException();
    }
}

// Orthodox

Bureaucrat::Bureaucrat() : _name(__BUREAUCRAT_DEFAULT_NAME__), _grade(__BUREAUCRAT_DEFAULT_GRADE__)
{
    // In case of miss configuration
    sb_check_grade_too_low(_grade);
    sb_check_grade_too_high(_grade);

    std::cout << "Bureaucrat <" << _name << "> (" << _grade 
                << ") is applied via default constructor program" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int const grade) : _name(name), _grade(grade)
{
    sb_check_grade_too_low(_grade);
    sb_check_grade_too_high(_grade);

    std::cout << "Bureaucrat <" << _name << "> (" << _grade 
                << ") is applied via constructor program" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const& obj) : _name(obj.getName()), _grade(obj.getGrade())
{
    std::cout << "Bureaucrat <" << _name << "> (" << _grade 
                << ") is splited via copy constructor technology" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat <" << _name << "> (" << _grade 
                << ") is retired via deconstructor program" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs)
{
    std::cout << "Bureaucrat <" << rhs.getName() << "> (" << rhs.getGrade() << ")" 
                << " applied grade to Bureaucrat <" << _name << "> (" << _grade << ")" 
                << " with Grade " << rhs.getGrade() << std::endl;

    _grade = rhs.getGrade();

    return *this;
}

// Getter

std::string const&  Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

// Grade Changer

void    Bureaucrat::incrementGrade()
{
    int tmp_grade = _grade - 1;

    sb_check_grade_too_high(tmp_grade);
    _grade = tmp_grade;
}

void    Bureaucrat::decrementGrade()
{
    int tmp_grade = _grade + 1;

    sb_check_grade_too_low(tmp_grade);
    _grade = tmp_grade;
}

// Sign

void    Bureaucrat::signForm(Form& form)
{
    if (form.getIsSigned())
    {
        std::cout << _name << " couldn't sign " << form.getName() 
                    << " because it's already signed" << std::endl;
        return;
    }

    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (Form::GradeTooLowException const& e)
    {
        std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

// Exception

Bureaucrat::GradeTooHighException::GradeTooHighException() : GradeOutOfBoundException("Bureaucrat's grade is too high") {}

Bureaucrat::GradeTooLowException::GradeTooLowException() : GradeOutOfBoundException("Bureaucrat's grade is too low") {}

// ostream

std::ostream&   operator<<(std::ostream& out, Bureaucrat const& rhs)
{
    out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();

    return out;
}