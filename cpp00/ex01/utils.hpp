/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:36:05 by tponutha          #+#    #+#             */
/*   Updated: 2023/11/09 10:41:08 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP
# include <iostream>
# include <sstream>
# include <cstdlib>

# ifndef READ_NO
#  define READ_NO 3
# endif

void	ft_prompt(std::string prmpt, std::string &line);
bool	ft_is_number(std::string str);
bool	ft_is_alphabet(std::string str);
bool	ft_convert_index(std::string str, int &num);

#endif