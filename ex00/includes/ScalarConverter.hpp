/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:08:58 by pineau            #+#    #+#             */
/*   Updated: 2024/03/31 13:37:33 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>

class ScalarConverter
{
	public:
		
		static void convert(std::string const & str);
		static bool	check_int(std::string const & str);
		static bool	check_float(std::string const & str);
		static bool	check_double(std::string const & str);
		static void	is_char(std::string const & str);
		static void	is_int(std::string const & str);
		static void	is_float(std::string const & str);
		static void	is_double(std::string const & str);
		static void	is_inf(std::string const & str);
		static void	is_nan(std::string const & str);
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		ScalarConverter & operator=(ScalarConverter const & rhs);
};

#endif