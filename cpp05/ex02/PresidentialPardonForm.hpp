/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:41:26 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/16 19:57:53 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIAL_PARDON_FORM_HPP__
#define __PRESIDENTIAL_PARDON_FORM_HPP__
#include "AForm.hpp"

#ifndef __PRESIDENTIAL_PARDON_FORM_NAME__
#define __PRESIDENTIAL_PARDON_FORM_NAME__ "presidential pardon"
#endif

#ifndef __PRESIDENTIAL_PARDON_FORM_DEFAULT_TARGET__
#define __PRESIDENTIAL_PARDON_FORM_DEFAULT_TARGET__ "Name Surname"
#endif

#ifndef __PRESIDENTIAL_PARDON_FORM_SIGN_GRADE__
#define __PRESIDENTIAL_PARDON_FORM_SIGN_GRADE__ 25
#endif

#ifndef __PRESIDENTIAL_PARDON_FORM_EXECUTE_GRADE__
#define __PRESIDENTIAL_PARDON_FORM_EXECUTE_GRADE__ 5
#endif

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string const& target);
        PresidentialPardonForm(PresidentialPardonForm const& obj);
        ~PresidentialPardonForm();
        PresidentialPardonForm& operator=(PresidentialPardonForm const& rhs);

        // executor
        void    execute(Bureaucrat const& executor) const;
};

#endif