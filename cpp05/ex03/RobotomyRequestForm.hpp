/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:41:23 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/16 20:00:38 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMY_REQUEST_FORM_HPP__
#define __ROBOTOMY_REQUEST_FORM_HPP__
#include "AForm.hpp"

#ifndef __ROBOTOMY_REQUEST_FORM_NAME__
#define __ROBOTOMY_REQUEST_FORM_NAME__ "robotomy request"
#endif

#ifndef __ROBOTOMY_REQUEST_FORM_DEFAULT_TARGET__
#define __ROBOTOMY_REQUEST_FORM_DEFAULT_TARGET__ "Robot Request"
#endif

#ifndef __ROBOTOMY_REQUEST_FORM_SIGN_GRADE__
#define __ROBOTOMY_REQUEST_FORM_SIGN_GRADE__ 72
#endif

#ifndef __ROBOTOMY_REQUEST_FORM_EXECUTE_GRADE__
#define __ROBOTOMY_REQUEST_FORM_EXECUTE_GRADE__ 45
#endif

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const& target);
        RobotomyRequestForm(RobotomyRequestForm const& obj);
        ~RobotomyRequestForm();
        RobotomyRequestForm&    operator=(RobotomyRequestForm const& rhs);

        // executor
        void    execute(Bureaucrat const& executor) const;
};

#endif