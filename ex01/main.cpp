/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 20:13:40 by roblabla          #+#    #+#             */
/*   Updated: 2015/06/24 20:13:54 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Data.hpp"

void		randomValue(char *tab)
{
	char	r;
	int		i = 0;

	while (i < 8)
	{
		r = rand() % (0-127);
		if ((r < 91 && r > 64) || (r > 96 && r < 123))
		{
			tab[i] = r;
			i++;
		}
	}
	tab[i] = '\0';
}

void		*serialize( void )
{
	char	*raw = new char[21];
	int		*rawint;
	int		n = rand();
	char	str1[9];
	char	str2[9];
	
	randomValue(str1);
	randomValue(str2);

	std::cout << str1 << std::endl;
	std::cout << n << std::endl;
	std::cout << str2 << std::endl;
	std::cout << "=========================" << std::endl;
	for(int i = 0; i < 8; ++i)
		raw[i] = str1[i];
	rawint = reinterpret_cast<int*>(&raw[8]);
	*rawint = n;
	/*raw[8] = static_cast<char>(n);
	raw[9] = static_cast<char>(n >> 8);
	raw[10] = static_cast<char>(n >> 16);
	raw[11] = static_cast<char>(n >> 24);*/
	for(int i = 0; i < 8; ++i)
		raw[i + 12] = str2[i];
	return raw;
}

Data		*deserialize( void *raw )
{
	int		i = 0;
	int		nbr = 0;
	int		*nbrint;
	Data	*data = new Data;

	char	*str = static_cast<char*>(raw);
	while (i < 20)
	{
		if (i < 8)
			data->s1 += str[i];
		else if (i == 8)
		{
			nbrint = reinterpret_cast<int*>(&str[i]);
			nbr = *nbrint;
			i += 3;
			data->n = nbr;
		}
		else
			data->s2 += str[i];
		i++;
	}
	return data;
}

int			main(void)
{
	srand(time(NULL));
	void	*raw;
	Data	*data;

	raw = serialize();
	data = deserialize(raw);
	std::cout << data->s1 << std::endl;
	std::cout << data->n << std::endl;
	std::cout << data->s2 << std::endl;
	
	return 0;
}
