/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 06:07:17 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/12 17:20:51 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
#define __FORM_HPP__

// Project Header
#include "GradeOutOfBoundException.hpp"
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

class Form
{
    private:
        std::string const   _name;
        bool                _isSigned;
        int const           _signGradeThreshold;
        int const           _executeGradeThreshold;
    
    public:
        Form();
        Form(std::string const& name, int const signGrade, int const executeGrade);
        Form(Form const& obj);
        ~Form();
        Form&   operator=(Form const& rhs);

        // Exception
        // Grade Too High
        class GradeTooHighException : public GradeOutOfBoundException
        {
            public:
                explicit GradeTooHighException(const char* msg);
        };

        // Grade Too Low
        class GradeTooLowException : public GradeOutOfBoundException
        {
            public:
                explicit GradeTooLowException(const char* msg);
        };

        // Getter
        std::string const&  getName() const;
        bool                getIsSigned() const;
        int                 getSignGradeThreshold() const;
        int                 getExecuteGradeThreshold() const;

        // Signed
        void    beSigned(Bureaucrat const& signer);
};

std::ostream&   operator<<(std::ostream& out, Form const& rhs);

#endif