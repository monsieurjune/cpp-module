/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:23:08 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/16 20:28:43 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_HPP__
#define __INTERN_HPP__
#include "AForm.hpp"
#include <string>

class Intern
{
    private:
        typedef struct s_pair
        {
            std::string name;
            AForm*      (*create)(std::string const&);
        } t_pair;

        t_pair  makePair(std::string const& name, AForm* (*fn)(std::string const&));

        static AForm*  createPresidentialPardonForm(std::string const& target);
        static AForm*  createRobotomyRequestForm(std::string const& target);
        static AForm*  createShrubberyCreationForm(std::string const& target);

    public:
        Intern();
        Intern(Intern const& rhs);
        ~Intern();
        Intern& operator=(Intern const& rhs);
        AForm* makeForm(std::string const& name, std::string const& target);
};


#endif