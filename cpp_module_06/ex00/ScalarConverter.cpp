/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:04:05 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/23 17:18:58 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter const &cpy){(void)cpy;}

ScalarConverter::~ScalarConverter(){}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
    return (*this);
}

void ScalarConverter::convert(std::string str)
{
	char	c = 0;
	int		i = 0;
	float	f = 0;
	double	d = 0;
	// bool	isCharacters = false;
	// if (!str.compare(".f"))
	// {
	// 	std::cout << "invalid argument" << std::endl;
	// 	return ;
	// }
	// for (int i = 0; str[i]; i++)
	// {
	// 	if (str[i] < '0' || str[i] > '9')
	// 	{
	// 		if (str[i] != '.' && str[i] != 'f')
	// 			isCharacters = true;
	// 	}
	// 	if ((isCharacters && str.length() > 1) || (str.find(".") != str.rfind(".")) || (str.find("f") != str.rfind("f")))
	// 	{
	// 		std::cout << "invalid argument" << std::endl;
	// 		return ;
	// 	}
	// }
	if ((str.find('.') != str.rfind('.')) || (str.find('f') != str.rfind('f')) || (str.find(".") != std::string::npos && str.find('f') < str.find('.')))
	{
		std::cout << "invalid argument" << std::endl;
		return;
	}
	try{std::stof(str);}catch(std::out_of_range){std::cout << "invalid argument" << std::endl; return;}
	catch(std::invalid_argument){if (str.length() > 1){std::cout << "invalid argument" << std::endl; return;}}
	if ((str.length() == 1 && str[0] >= 0 && str[0] <= 47) || (str[0] >= 58 && str[0] <= 126))
	{
		std::cout << "char" << std::endl;
		c = str[0];
		i = static_cast<int>(c);
		d = static_cast<double>(c);
		c = static_cast<char>(c);
	}
	else if (str.find("f") == std::string::npos && str.length() > 1 && (str.find(".") != std::string::npos || std::stof(str) > 2147483647 || std::stof(str) < -2147483648))
	{
		std::cout << "double" << std::endl;
		d = std::stod(str);
		i = static_cast<int>(d);
		d = static_cast<double>(d);
		c = static_cast<char>(d);
	}
	else if (str.length() > 1 /*&& str.find(".") != std::string::npos*/ && str.find("f") != std::string::npos)
	{
		std::cout << "float" << std::endl;
		f = std::stof(str);
		i = static_cast<int>(f);
		d = static_cast<double>(f);
		c = static_cast<char>(f);
	}
	else //if (str.find(".") == std::string::npos && str.find("f") == std::string::npos)
	{
		std::cout << "int" << std::endl;
		i = std::stoi(str);
		f = static_cast<float>(i);
		d = static_cast<double>(i);
		c = static_cast<char>(i);
	}
	if (f != f || std::numeric_limits<float>::infinity() == f)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else if (f > 2147483647 || f < -2147483648)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		if (c < 33 || c > 126)
			std::cout << "char: non displayable" << std::endl;
		else
			std::cout << "char: " << c << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}
}

// void ScalarConverter::convert(std::string str)
// {
// 	float	f = 0;
// 	int		exc = 0;
// 	try{f = std::stof(str);}
// 	catch(const std::exception& e){exc = 1;}
// 	if (exc && str.length() == 1)
// 		f = static_cast<float>(str[0]);
// 	else if (exc)
// 	{
// 		std::cout << "invalid argument" << std::endl;
// 		return ;
// 	}
// 	if (f != f)
// 	{
// 		std::cout << "char: impossible" << std::endl;
// 		std::cout << "int: impossible" << std::endl; 
// 		std::cout << "float: nanf" << std::endl;
// 		std::cout << "double: nan" << std::endl;
// 	}
// 	else if (std::numeric_limits<float>::infinity() == f)
// 	{
// 		std::cout << "char: impossible" << std::endl;
// 		std::cout << "int: impossible" << std::endl; 
// 		std::cout << "float: inff" << std::endl;
// 		std::cout << "double: inf" << std::endl;
// 	}
// 	else if (-std::numeric_limits<float>::infinity() == f)
// 	{
// 		std::cout << "char: impossible" << std::endl;
// 		std::cout << "int: impossible" << std::endl; 
// 		std::cout << "float: -inff" << std::endl;
// 		std::cout << "double: -inf" << std::endl;
// 	}
// 	else
// 	{
// 		if (f >= 33 && f <= 126)
// 			std::cout << "char: " << static_cast<char>(f) << std::endl;
// 		else if (f < 33)
// 			std::cout << "char: non displayable" << std::endl;
// 		else 
// 			std::cout << "char: impossible" << std::endl;
// 		if (f >= 2147483647 || f <= -2147483648)
// 			std::cout << "int: overflow" << std::endl;
// 		else
// 			std::cout << "int: " << static_cast<int>(f) << std::endl;
// 		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
// 		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
// 	}
// }