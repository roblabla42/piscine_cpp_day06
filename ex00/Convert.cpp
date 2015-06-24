/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 21:13:45 by roblabla          #+#    #+#             */
/*   Updated: 2015/06/24 21:13:46 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include <iostream>
#include <cmath>
#include <limits>

Convert::Convert() {
}

Convert::Convert(Convert const &rhs) {
	(void)rhs;
}

Convert & Convert::operator=(Convert const &rhs) {
	(void)rhs;
	return (*this);
}

Convert::~Convert() {
}

int		Convert::getPrecision(std::string str) {
	size_t len = str.find(".");

	if (len != std::string::npos)
	{
		if ((str.find(".", len + 1)) != std::string::npos)
			throw Convert::impossibleException();
		if (str.c_str()[len + 1] != '\0')
		{
			if (str.find("f") != std::string::npos)
				++len;
			return (str.size() - (len + 1)); 
		}
		return (1);
	}
	return (1);
}

char	Convert::doubleToChar(double d) {
	char c;

	if (isinf(d) == true || isnan(d) == true)
		throw Convert::impossibleException();
	if (d > static_cast<double>(std::numeric_limits<char>::max()) ||
		d < static_cast<double>(std::numeric_limits<char>::min()))
		throw Convert::impossibleException();
	if (static_cast<int>(d) == 0)
		throw Convert::noneDisplayableException();
	c = static_cast<char>(static_cast<int>(d));
	return (c);
}

int		Convert::doubleToInt(double d) {
	if (isinf(d) == true || isnan(d) == true)
		throw Convert::impossibleException();
	else if (d > static_cast<double>(std::numeric_limits<int>::max()) ||
			d < static_cast<double>(std::numeric_limits<int>::min()))
		throw Convert::impossibleException();
	return (static_cast<int>(d));
}

float	Convert::doubleToFloat(double d) {
	return (static_cast<float>(d));
}

double	Convert::doubleToDouble(double d) {
	return (d);
}
/* ****************************************************************************
 * Impossible Exception
 * ***************************************************************************/

Convert::impossibleException & Convert::impossibleException::operator=(Convert::impossibleException const &rhs) throw(){
	(void) rhs;
	return (*this);
}
Convert::impossibleException::impossibleException(Convert::impossibleException const &rhs) throw(){
	(void) rhs;
}
Convert::impossibleException::impossibleException(void) throw() {

}
Convert::impossibleException::~impossibleException() throw(){

}
const char *Convert::impossibleException::what() const throw() {
	return (std::string("Impossible").c_str());
}

/* ****************************************************************************
 * NoneDisplayable Exception
 * ***************************************************************************/

Convert::noneDisplayableException & Convert::noneDisplayableException::operator=(Convert::noneDisplayableException const &rhs) throw(){
	(void)rhs;
	return (*this);
}
Convert::noneDisplayableException::noneDisplayableException(Convert::noneDisplayableException const &rhs) throw(){
	(void)rhs;
}
Convert::noneDisplayableException::noneDisplayableException(void) throw() {

}
Convert::noneDisplayableException::~noneDisplayableException() throw(){

}
const char *Convert::noneDisplayableException::what() const throw() {
	return (std::string("None Displayable").c_str());
}

