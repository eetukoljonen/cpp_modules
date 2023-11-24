/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:04:05 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/24 16:47:47 by ekoljone         ###   ########.fr       */
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
	int		str_len = str.length();
	try{std::stod(str);}
	catch(std::out_of_range)
	{
		std::cout	<< "char: impossible" << std::endl
					<< "int: impossible" << std::endl
					<< "float: impossible" << std::endl
					<< "double: impossible" << std::endl;
		return ;
	}
	catch(std::invalid_argument)
	{
		if (str.length() > 1)
		{
			std::cout << "invalid argument" << std::endl;
			return;
		}
	}
	if (str_len == 1 && ((str[0] >= 0 && str[0] <= 47)
		|| (str[0] >= 58 && str[0] <= 127)))
	{
		std::cout << "char" << std::endl;
		c = str[0];
		i = static_cast<int>(c);
		d = static_cast<double>(c);
		f = static_cast<float>(c);
	}
	else if (str.compare("nanff") && str.compare("inff") && str.compare("-inff")
			&& ((str.find("f") == std::string::npos && str_len > 1 && str.find(".") != std::string::npos)
			|| std::stod(str) > std::numeric_limits<float>::max()
			|| std::stod(str) < -std::numeric_limits<float>::max()
			|| !str.compare("nan")))
	{
		std::cout << "double" << std::endl;
		d = std::stod(str);
		i = static_cast<int>(d);
		f = static_cast<float>(d);
		c = static_cast<char>(d);
	}
	else if ((str_len > 1 && str.find("f") != std::string::npos)
			|| std::stod(str) > std::numeric_limits<int>::max()
			|| std::stod(str) < std::numeric_limits<int>::min()
			|| !str.compare("nanf")
			|| !str.compare("inff")
			|| !str.compare("-inff"))
	{
		std::cout << "float" << std::endl;
		f = std::stof(str);
		i = static_cast<int>(f);
		d = static_cast<double>(f);
		c = static_cast<char>(f);
	}
	else
	{
		std::cout << "int" << std::endl;
		i = std::stoi(str);
		f = static_cast<float>(i);
		d = static_cast<double>(i);
		c = static_cast<char>(i);
	}
	if (d != d || std::numeric_limits<double>::infinity() == d
		|| -std::numeric_limits<double>::infinity() == d)
	{
		std::cout	<< "char: impossible" << std::endl
					<< "int: impossible" << std::endl
					<< "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
	else if (d > std::numeric_limits<int>::max()
			|| d < -std::numeric_limits<int>::max())
	{
		std::cout	<< "char: impossible" << std::endl
					<< "int: impossible" << std::endl;
		if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
			std::cout << "float: impossible" << std::endl;
		else
			std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
	else
	{
		if (d < 0 || d > 127)
			std::cout << "char: impossible" << std::endl;
		else if (d < 33 || d > 126)
			std::cout << "char: non displayable" << std::endl;
		else
			std::cout << "char: " << c << std::endl;
		std::cout	<< "int: " << i << std::endl
					<< "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
