/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla <robinlambertz+dev@gmail.c>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/24 21:13:52 by roblabla          #+#    #+#             */
/*   Updated: 2015/06/24 21:13:52 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONVERT_HPP
# define CONVERT_HPP

#include <exception>
#include <string>

class Convert {

	private :

	public :
		class impossibleException;
		class noneDisplayableException;
		Convert(void);
		Convert(Convert const &rhs);
		Convert & operator=(Convert const &rhs);
		virtual ~Convert();
		static int		getPrecision(std::string str);
		static char		doubleToChar(double v_double);
		static int		doubleToInt(double v_double);
		static float	doubleToFloat(double v_double);
		static double	doubleToDouble(double v_double);
};


class Convert::impossibleException : public std::exception{

	private :
		impossibleException & operator=(impossibleException const &rhs) throw();

	public :
		impossibleException(void) throw();
		impossibleException(impossibleException const &rhs) throw();
		virtual ~impossibleException() throw();
		virtual const char *what() const throw();
};


class Convert::noneDisplayableException : public std::exception
{
	protected :
		noneDisplayableException & operator=(noneDisplayableException const &rhs) throw();

	public :
		noneDisplayableException(noneDisplayableException const &rhs) throw();
		noneDisplayableException(void) throw();
		virtual ~noneDisplayableException() throw();
		virtual const char *what() const throw();
};

#endif
