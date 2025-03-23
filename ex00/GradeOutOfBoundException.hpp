/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeOutOfBoundException.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 06:45:05 by tponutha          #+#    #+#             */
/*   Updated: 2025/03/24 03:45:47 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GRADE_OUT_OF_BOUND_EXCEPTION_HPP__
#define __GRADE_OUT_OF_BOUND_EXCEPTION_HPP__
#include <exception>
#include <string>

class GradeOutOfBoundException : public std::exception
{
    private:
        std::string _msg;
    
    public:
        explicit GradeOutOfBoundException(const char* msg);
        explicit GradeOutOfBoundException(std::string const& msg);
        virtual ~GradeOutOfBoundException() throw();
        virtual const char* what() const throw();
};

#endif