/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 03:19:00 by tponutha          #+#    #+#             */
/*   Updated: 2023/11/12 16:58:34 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl			harl;
	std::string		av;
	
	if (argc != 2)
	{
		std::cerr << "Harl filter can take 1 argument only !!" << std::endl;
	}
	av = std::string (argv[1]);
	for (size_t i = 0; i < av.length(); i++)
	{
		av[i] = tolower(av[i]);
	}
	harl.filter(av);
	return (0);
}