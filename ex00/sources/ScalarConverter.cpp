/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:08:55 by pineau            #+#    #+#             */
/*   Updated: 2024/04/01 15:17:54 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const & src) {
	*this = src;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs) {
	(void)rhs;
	return *this;
}

void	ScalarConverter::convert(std::string const & str) {
	
	if (str.length() == 0)
		return ;
	if (str.compare("-inf") == 0 || str.compare("+inf") == 0 || str.compare("-inff") == 0 || str.compare("+inff") == 0)
		return (is_inf(str));
	else if (str.compare("nan") == 0 || str.compare("nanf") == 0)
		return (is_nan(str));
	if (str.length() == 1 && !isdigit(str[0]))
		return is_char(str);
	else if (check_int(str))
		return is_int(str);
	else if (check_float(str))
		return is_float(str);
	else if (check_double(str))
		return is_double(str);
	else
		is_impossible();
	std::cout << "Use only char, int, float or double" << std::endl;
}

bool ScalarConverter::check_int(std::string const & str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			continue;
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::check_float(std::string const & str) {
	int j = 0;
	int k = 0;
	for (size_t i = 0; i < str.length(); i++) {
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			continue;
		if (str[i] == '.')
			j++;
		if (j > 1)
			return false;
		if (!isdigit(str[i]))
			k++;
		if (k > 2)
			return false;
		if(str[i] == '.' && str[i + 1] == 'f')
			return false;
	}
	if (str[str.length() - 1] != 'f')
		return false;
	return true;
}

bool ScalarConverter::check_double(std::string const & str) {
	int j = 0;
	for (size_t i = 0; i < str.length(); i++) {
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			continue;
		if (str[i] == '.')
		{
			j++;
			continue;
		}
		if (j > 1)
			return false;
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

void	ScalarConverter::is_impossible() {
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;
	std::cout << "float: Impossible" << std::endl;
	std::cout << "double: Impossible" << std::endl;
}

void	ScalarConverter::is_char(std::string const & str) {
	char c = str[0];
	if (c < 0 || c > 126)
		std::cout << "char: Impossible" << std::endl;
	if (c < 32)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	ScalarConverter::is_int(std::string const & str) {
	long int i = atol(str.c_str());
	if (i > 2147483647 || i < -2147483648)
		return is_impossible();
	if(i < 0 || i > 127)
		std::cout << "char: Impossible" << std::endl;
	else if (i < 32)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(i) << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::is_float(std::string const & str) {
	long int i = atol(str.c_str());
	if (i > 2147483647 || i < -2147483648)
		return is_impossible();
	float f = atof(str.c_str());
	if(f < 0 || f > 127)
		std::cout << "char: Impossible" << std::endl;
	else if (f < 32)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float2: " << static_cast<float>(f) << "f" << std::endl;
	std::cout << "double2: " << static_cast<double>(f) << std::endl;
	
}

void ScalarConverter::is_double(std::string const & str) {
	long int i = atol(str.c_str());
	if (i > 2147483647 || i < -2147483648)
		return is_impossible();
	double d = atof(str.c_str());
	if(d < 0 || d > 127)
		std::cout << "char: Impossible" << std::endl;
	else if (d < 32)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(d) << std::endl;
}

void ScalarConverter::is_inf(std::string const & str) {
	if (str[0] == '+')
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str[0] == '-')
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::is_nan(std::string const & str) {
	(void)str;
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}