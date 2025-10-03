/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponutha <tponutha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 03:37:17 by tponutha          #+#    #+#             */
/*   Updated: 2023/11/12 16:33:30 by tponutha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <fstream>

static bool	file_open(std::string name, std::ifstream &infile, std::ofstream &outfile)
{
	infile.open(name.data(), std::ios::in);
	if (!infile.is_open())
	{
		std::cerr << "File : " << name << "is permission/file error" << std::endl;
		return false;
	}
	name.append(".replace");
	outfile.open(name.data(), std::ios::out | std::ios::trunc);
	if (!outfile.is_open())
	{
		std::cerr << "File : " << name << "is permission/file error" << std::endl;
		infile.close();
		return false;
	}
	return true;
}

static void	write_sed(std::ofstream &outfile, std::string res, std::string s1, std::string s2)
{
	size_t	n;

	while (!res.empty() && outfile.good())
	{
		n = res.find(s1, 0);
		outfile << res.substr(0, n);
		if (n == (size_t)-1)
		{
			return;
		}
		outfile << s2;
		res.erase(0, n + 1);
	}
}

static bool	file_read(std::ifstream &infile, std::string &res)
{
	std::ostringstream	tmp;

	if (!infile.good())
	{
		return false;
	}
	tmp << infile.rdbuf();
	res = tmp.str();
	return true;
}

int	main(int ac, char **av)
{
	std::ofstream	outfile;
	std::ifstream	infile;
	std::string		res;
	std::string		line;

	if (ac != 4)
	{
		std::cerr << "There must be 4 arguments" << std::endl;
		return 0;
	}
	if (!file_open(av[1], infile, outfile))
	{
		return 1;
	}
	if (file_read(infile, res))
	{
		write_sed(outfile, res, av[2], av[3]);
	}
	infile.close();
	outfile.close();
	return 0;
}
