/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:41:18 by tponutha          #+#    #+#             */
/*   Updated: 2025/04/03 14:06:41 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERY_CREATION_FORM_HPP__
#define __SHRUBBERY_CREATION_FORM_HPP__
#include "AForm.hpp"

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