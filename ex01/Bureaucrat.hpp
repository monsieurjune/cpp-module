/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:53:02 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/16 21:20:33 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

// CPP Header
#include <iosfwd>
#include <string>
#include <exception>

#ifndef __BUREAUCRAT_HIGHEST_GRADE__
#define __BUREAUCRAT_HIGHEST_GRADE__ 1
#endif

#ifndef __BUREAUCRAT_LOWEST_GRADE__
#define __BUREAUCRAT_LOWEST_GRADE__ 150
#endif

#ifndef __BUREAUCRAT_DEFAULT_NAME__
#define __BUREAUCRAT_DEFAULT_NAME__ "bureaucratic moment"
#endif

#ifndef __BUREAUCRAT_DEFAULT_GRADE__
#define __BUREAUCRAT_DEFAULT_GRADE__ __BUREAUCRAT_LOWEST_GRADE__
#endif

// Declaration (avoid circular include)
class Form;

class Bureaucrat
{
    private:
        std::string const   _name;
        int                 _grade;
    
    public:
        Bureaucrat();
        Bureaucrat(std::string const& name, int const grade);
        Bureaucrat(Bureaucrat const& obj);
        ~Bureaucrat();
        Bureaucrat& operator=(Bureaucrat const& rhs);

        // Exception
        // Grade Too High
        class GradeTooHighException : public std::exception
        {
            private:
                std::string _msg;

            public:
                explicit GradeTooHighException();
                virtual ~GradeTooHighException() throw();
                virtual const char* what() const throw();
        };

        // Grade Too Low
        class GradeTooLowException : public std::exception
        {
            private:
                std::string _msg;

            public:
                explicit GradeTooLowException();
                virtual ~GradeTooLowException() throw();
                virtual const char* what() const throw();
        };

        // Getter
        std::string const&  getName() const;
        int                 getGrade() const;

        // Grade Changer
        void    incrementGrade();
        void    decrementGrade();

        // Form
        void    signForm(Form& form);
};

std::ostream&   operator<<(std::ostream& out, Bureaucrat const& rhs);

#endif