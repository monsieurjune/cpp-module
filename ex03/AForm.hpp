/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:41:33 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/15 08:43:58 by tponutha         ###   ########.fr       */
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
#define __FORM_DEFAULT_NAME__ "XXXX"
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
        std::string const   _target;
        bool                _isSigned;
        int const           _signGradeThreshold;
        int const           _executeGradeThreshold;

    public:
        AForm();
        AForm(std::string const& name, std::string const& target, int const signGrade, int const executeGrade);
        AForm(AForm const& obj);
        virtual ~AForm();
        AForm&  operator=(AForm const& rhs);

        // Exception
        // Grade Too High
        class GradeTooHighException : public BaseBureaucraticException
        {
            public:
                explicit GradeTooHighException(std::string const& msg);
        };

        // Grade Too Low
        class GradeTooLowException : public BaseBureaucraticException
        {
            public:
                explicit GradeTooLowException(std::string const& msg);
        };

        // Execution failed
        class ExecutionFailedException : public BaseBureaucraticException
        {
            public:
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
        std::string const&  getTarget() const;
        bool                getIsSigned() const;
        int                 getSignGradeThreshold() const;
        int                 getExecuteGradeThreshold() const;

        // Sign
        void    beSigned(Bureaucrat const& signer);

        // Execute
        virtual void    execute(Bureaucrat const& executor) const = 0;
};

std::ostream&   operator<<(std::ostream& out, AForm const& rhs);

#endif