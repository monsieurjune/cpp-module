/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:23:08 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/16 18:31:21 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_HPP__
#define __INTERN_HPP__
#include "AForm.hpp"
#include <string>

class Intern
{
    private:
        AForm*  createPresidentialPardonForm(std::string const& target);
        AForm*  createRobotomyRequestForm(std::string const& target);
        AForm*  createShrubberyCreationForm(std::string const& target);

        typedef struct s_pair
        {
            std::string name;
            AForm*      (Intern::*create)(std::string const&);
        } t_pair;
        t_pair  makePair(std::string const& name, AForm* (Intern::*fn)(std::string const&));

    public:
        Intern();
        Intern(Intern const& rhs);
        ~Intern();
        Intern& operator=(Intern const& rhs);
        AForm* makeForm(std::string const& name, std::string const& target);
};


#endif