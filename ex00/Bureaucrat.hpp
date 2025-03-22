/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:53:02 by tponutha          #+#    #+#             */
/*   Updated: 2025/03/23 03:31:34 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__
#include <iostream>
#include <exception>
#include <string>

class Bureaucrat
{
    private:
        std::string const   _name;
        int                 _grade;
    
    public:
        Bureaucrat();
        Bureaucrat(Bureaucrat const& obj);
        ~Bureaucrat();
        Bureaucrat& operator=(Bureaucrat const& rhs);

        // Exception

        // Grade Too High
        class GradeTooHighException : public std::exception
        {
            private:
                std::string const   _msg;
            
            public:
                GradeTooHighException();
                virtual ~GradeTooHighException() throw();
                virtual const char* what() const throw();
        };

        // Grade Too Low
        class GradeTooLowException : public std::exception
        {
            private:
                std::string const   _msg;

            public:
                GradeTooLowException();
                virtual ~GradeTooLowException() throw();
                virtual const char* what() const throw();
        };

        // Getter
        std::string const&  getName();
        int                 getGrade();

        // Grade Changer
        void    incrementGrade();
        void    decrementGrade();
};

std::ostream&   operator<<(std::ostream& out, Bureaucrat const& rhs);

#endif