/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 21:14:00 by roblabla          #+#    #+#             */
/*   Updated: 2015/06/24 21:14:01 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Convert.hpp"
#include <iomanip>

#define WAT what

template <typename T>
static void trycatch(std::string conv, T (*fn)(double), double d, int precision)
{
	(void)precision;
	try {
		std::cout << conv << " : "; 
		if (conv == "char" && fn(d))
			std::cout << "'" << fn(d) << "'" << std::endl;
		else if (conv == "float")
			std::cout << std::fixed << std::setprecision(precision) << fn(d) << "f" << std::endl;
		else if (conv == "double")
			std::cout << std::fixed << std::setprecision(precision) << fn(d) << std::endl;
		else
			std::cout << fn(d) << std::endl;
	} catch (std::exception &e)
	{
		std::cout << e.WAT() << std::endl;
	}
}

int		main(int ac, char **av) {

	Convert conv;
	int		precision = 1;
	double d;

	if (ac == 2)
	{
		if ((std::string(av[1]).size() == 3 && av[1][0] == '\'' && av[1][2] == '\''))
			d = static_cast<double>(static_cast<int>(av[1][1]));
		else if (std::string(av[1]).size() == 1 && av[1][0] >= 'a' && av[1][0] <= 'z')
			d = static_cast<double>(static_cast<int>(av[1][0]));
		else
		{
			d = std::atof(av[1]);
			precision = conv.getPrecision(std::string(av[1]));
		}

		trycatch("char", &conv.doubleToChar, d, precision);
		trycatch("int", &conv.doubleToInt, d, precision);
		trycatch("float", &conv.doubleToFloat, d, precision);
		trycatch("double", &conv.doubleToDouble, d, precision);
	}
	else
		std::cout << "Missing parameters" << std::endl;
	return (0);
}
