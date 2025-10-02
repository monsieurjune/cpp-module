/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:34:07 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/16 20:28:57 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

Intern::Intern() {}

Intern::Intern(Intern const& rhs)
{
    (void)rhs;
}

Intern::~Intern() {}

Intern& Intern::operator=(Intern const& rhs)
{
    (void)rhs;
    return *this;
}

AForm* Intern::makeForm(std::string const& name, std::string const& target)
{
    t_pair  pairSet[] = {
                    makePair("presidential pardon", createPresidentialPardonForm),
                    makePair("robotomy request", createRobotomyRequestForm),
                    makePair("shrubbery creation", createShrubberyCreationForm),
                };

    // Linear Search
    for (size_t i = 0; i < sizeof(pairSet) / sizeof(t_pair); i++)
    {
        if (name == pairSet[i].name)
        {
            try
            {
                std::cout << "Intern creates " << name << std::endl;
                return (pairSet[i].create)(target);
            }
            catch (std::bad_alloc const&)
            {
                break;
            }
        }
    }

    std::cout << "Intern can\'t create " << name << std::endl;
    return NULL;
}

Intern::t_pair  Intern::makePair(std::string const& name, AForm* (*fn)(std::string const&))
{
    t_pair  pair;

    pair.name = name;
    pair.create = fn;

    return pair;
}

AForm*  Intern::createPresidentialPardonForm(std::string const& target)
{
    return new PresidentialPardonForm(target);
}

AForm*  Intern::createRobotomyRequestForm(std::string const& target)
{
    return new RobotomyRequestForm(target);
}

AForm*  Intern::createShrubberyCreationForm(std::string const& target)
{
    return new ShrubberyCreationForm(target);
}