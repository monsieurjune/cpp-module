/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:41:18 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/16 20:02:10 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERY_CREATION_FORM_HPP__
#define __SHRUBBERY_CREATION_FORM_HPP__
#include "AForm.hpp"

#ifndef __SHRUBBERY_CREATION_FORM_NAME__
#define __SHRUBBERY_CREATION_FORM_NAME__ "shrubbery creation"
#endif

#ifndef __SHRUBBERY_CREATION_FORM_DEFAULT_TARGET__
#define __SHRUBBERY_CREATION_FORM_DEFAULT_TARGET__ "Shrubbery"
#endif

#ifndef __SHRUBBERY_CREATION_FORM_SIGN_GRADE__
#define __SHRUBBERY_CREATION_FORM_SIGN_GRADE__ 145
#endif

#ifndef __SHRUBBERY_CREATION_FORM_EXECUTE_GRADE__
#define __SHRUBBERY_CREATION_FORM_EXECUTE_GRADE__ 137
#endif

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const& target);
        ShrubberyCreationForm(ShrubberyCreationForm const& obj);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm   operator=(ShrubberyCreationForm const& rhs);

        // executor
        void    execute(Bureaucrat const& executor) const;
};

#endif