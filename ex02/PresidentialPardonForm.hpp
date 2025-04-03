/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:41:26 by tponutha          #+#    #+#             */
/*   Updated: 2025/04/03 13:51:31 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIAL_PARDON_FORM_HPP__
#define __PRESIDENTIAL_PARDON_FORM_HPP__
#include "AForm.hpp"

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