/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseBureaucraticException.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:17:20 by tponutha          #+#    #+#             */
/*   Updated: 2025/05/10 20:16:56 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BASE_BUREAUCRAT_EXCEPTION_HPP__
#define __BASE_BUREAUCRAT_EXCEPTION_HPP__
#include <exception>
#include <string>

class BaseBureaucraticException : public std::exception
{
    private:
        std::string _msg;
    
    public:
        explicit BaseBureaucraticException(const char* msg);
        explicit BaseBureaucraticException(std::string const& msg);
        virtual ~BaseBureaucraticException() throw();
        virtual const char* what() const throw();
};

#endif