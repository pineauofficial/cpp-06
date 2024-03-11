/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:08:55 by pineau            #+#    #+#             */
/*   Updated: 2024/03/11 17:29:16 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(std::string const & str) {
	if (str.length() == 0)
		return ;
	if (str.compare("inf") == 0 || str.compare("-inf") == 0 || str.compare("+inf") == 0 || str.compare("inff") == 0 || str.compare("-inff") == 0 || str.compare("+inff") == 0)
		return (is_inf(str));
	else if (str.compare("nan") == 0 || str.compare("nanf") == 0)
		return (is_nan(str));
	if (str.length() == 1 && !isdigit(str[0]))
		is_char(str);
	else if (check_int(str))
		is_int(str);
	else if (check_float(str))
		is_float(str);
	else if (check_double(str))
		is_double(str);
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
		if (!isdigit(str[i]) && str[str.length()] != str[i])
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

void	ScalarConverter::is_char(std::string const & str) {
	char c = str[0];
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	ScalarConverter::is_int(std::string const & str) {
	int i = atoi(str.c_str());
	std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(i) << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::is_float(std::string const & str) {
	float f = atof(str.c_str());
	std::cout << "char: '*'" << std::endl;
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << static_cast<float>(f) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::is_double(std::string const & str) {
	double d = atof(str.c_str());
	std::cout << "char: '*'" << std::endl;
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(d) << std::endl;
}

void ScalarConverter::is_inf(std::string const & str) {
	if (str.compare("inf") || str.compare("+inf") || str.compare("inff") || str.compare("+inff"))
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
	else
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