/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:41:23 by tponutha          #+#    #+#             */
/*   Updated: 2025/04/03 13:58:05 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMY_REQUEST_FORM_HPP__
#define __ROBOTOMY_REQUEST_FORM_HPP__
#include "AForm.hpp"

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