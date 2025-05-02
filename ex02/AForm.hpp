/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:41:33 by tponutha          #+#    #+#             */
/*   Updated: 2025/04/04 14:53:04 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AFORM_HPP__
#define __AFORM_HPP__

// Project Header
#include "BaseBureaucraticException.hpp"
#include "Bureaucrat.hpp"

// CPP Header
#include <iosfwd>
#include <string>

#ifndef __FORM_HIGHEST_GRADE__
#define __FORM_HIGHEST_GRADE__ __BUREAUCRAT_HIGHEST_GRADE__
#endif

#ifndef __FORM_LOWEST_GRADE__
#define __FORM_LOWEST_GRADE__ __BUREAUCRAT_LOWEST_GRADE__
#endif

#ifndef __FORM_DEFAULT_NAME__
#define __FORM_DEFAULT_NAME__ "unknown form"
#endif

#ifndef __FORM_DEFAULT_SIGN_GRADE__
#define __FORM_DEFAULT_SIGN_GRADE__ __BUREAUCRAT_LOWEST_GRADE__
#endif

#ifndef __FORM_DEFAULT_EXECUTE_GRADE__
#define __FORM_DEFAULT_EXECUTE_GRADE__ __BUREAUCRAT_LOWEST_GRADE__
#endif

// Declaration (avoid circular include)
class Bureaucrat;

class AForm
{
    private:
        std::string const   _name;
        bool                _isSigned = false;
        int const           _signGradeThreshold;
        int const           _executeGradeThreshold;
    
    public:
        AForm();
        AForm(std::string const& name, int const signGrade, int const executeGrade);
        AForm(AForm const& obj);
        virtual ~AForm();
        AForm&  operator=(AForm const& rhs);

        // Exception
        // Grade Too High
        class GradeTooHighException : public BaseBureaucraticException
        {
            public:
                explicit GradeTooHighException(const char* grade_type);
        };

        // Grade Too Low
        class GradeTooLowException : public BaseBureaucraticException
        {
            public:
                explicit GradeTooLowException(const char* grade_type);
        };

        // Execution failed
        class ExecutionFailedException : public BaseBureaucraticException
        {
            public:
                explicit ExecutionFailedException(const char* msg);
                explicit ExecutionFailedException(std::string const& msg);
        };

        // Unsign Error
        class UnsignedFormException : public BaseBureaucraticException
        {
            public:
                explicit UnsignedFormException();
        };

        // Getter
        std::string const&  getName() const;
        bool                getIsSigned() const;
        int                 getSignGradeThreshold() const;
        int                 getExecuteGradeThreshold() const;

        // Sign
        bool    beSigned(Bureaucrat const& signer);

        // Execute
        virtual void    execute(Bureaucrat const& executor) const = 0;
};

#endif