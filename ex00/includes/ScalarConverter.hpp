/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:08:58 by pineau            #+#    #+#             */
/*   Updated: 2024/03/11 15:29:15 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		~ScalarConverter();
		ScalarConverter &	operator=(ScalarConverter const & rhs);
		
		void convert(std::string const & str);
		bool	check_int(std::string const & str);
		bool	check_float(std::string const & str);
		bool	check_double(std::string const & str);
		void	is_char(std::string const & str);
		void	is_int(std::string const & str);
		void	is_float(std::string const & str);
		void	is_double(std::string const & str);
		void	is_inf(std::string const & str);
		void	is_nan(std::string const & str);
};

#endif