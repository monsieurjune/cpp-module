/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:52:52 by tponutha          #+#    #+#             */
/*   Updated: 2025/03/24 04:23:22 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Project Header
#include "Bureaucrat.hpp"
#include "ft_std.hpp"

// CPP Header
#include <iostream>

// Helper

static inline std::string   sb_grade_exception_formatter(
                                std::string const& name, 
                                int const grade, 
                                const char* cause,
                                const char* minmax,
                                int minmax_val
                            )
{
    std::string str;

    str.append("Bureaucrat <");
    str.append(name);
    str.append("> (");
    str.append(ft_std::itoa(grade));
    str.append("): Grade is ");
    str.append(cause);
    str.append(" (");
    str.append(minmax);
    str.append(" grade is ");
    str.append(ft_std::itoa(minmax_val));
    str.append(")");

    return str;
}

static inline void  sb_check_grade_too_low(std::string const& name, int grade)
{
    if (grade > __BUREAUCRAT_LOWEST_GRADE__)
    {
        throw Bureaucrat::GradeTooLowException(name, grade);
    }
}

static inline void  sb_check_grade_too_high(std::string const& name, int grade)
{
    if (grade < __BUREAUCRAT_HIGHEST_GRADE__)
    {
        throw Bureaucrat::GradeTooHighException(name, grade);
    }
}

// Orthodox

Bureaucrat::Bureaucrat() : _name(__BUREAUCRAT_DEFAULT_NAME__), _grade(__BUREAUCRAT_DEFAULT_GRADE__)
{
    // In case of miss configuration
    sb_check_grade_too_low(_name, _grade);
    sb_check_grade_too_high(_name, _grade);

    std::cout << "Bureaucrat <" << _name << "> (" << _grade 
                << ") is applied via default constructor program" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int const grade) : _name(name), _grade(grade)
{
    sb_check_grade_too_low(_name, _grade);
    sb_check_grade_too_high(_name, _grade);

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

    sb_check_grade_too_high(_name, tmp_grade);
    _grade = tmp_grade;
}

void    Bureaucrat::decrementGrade()
{
    int tmp_grade = _grade + 1;

    sb_check_grade_too_low(_name, tmp_grade);
    _grade = tmp_grade;
}

// Exception

Bureaucrat::GradeTooHighException::GradeTooHighException(
    std::string const& name, 
    int grade
) : GradeOutOfBoundException(
    sb_grade_exception_formatter(name, grade, "too high", "max", __BUREAUCRAT_HIGHEST_GRADE__)
) {}

Bureaucrat::GradeTooLowException::GradeTooLowException(
    std::string const& name, 
    int grade
) : GradeOutOfBoundException(
    sb_grade_exception_formatter(name, grade, "too low", "min", __BUREAUCRAT_LOWEST_GRADE__)
) {}

// ostream

std::ostream&   operator<<(std::ostream& out, Bureaucrat const& rhs)
{
    out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();

    return out;
}