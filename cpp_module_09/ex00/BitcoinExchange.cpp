/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:03:17 by ekoljone          #+#    #+#             */
/*   Updated: 2023/12/14 19:24:28 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){parseData();}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &cpy)
{
	(void)cpy;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
	{

	}
	return (*this);
}

void	BitcoinExchange::parseData()
{
	std::string			line;
	std::ifstream		file("data.csv");
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		exit(1);
	}
	std::getline(file, line);
	while (file.is_open())
	{
		std::getline(file, line);
		if (line.empty() || file.eof())
			file.close();
		else
		{
			std::string date	= line.substr(0, line.find(","));
			std::string s_val	= line.substr(line.find(",") + 1, line.size());
			std::istringstream	iss(s_val);
			float value;
			iss >> value;
			this->_data[date] = value;
		}
	}
}

bool isValidDate(std::string date)
{
	std::time_t		t = std::time(NULL);
	std::tm *const	info = std::localtime(&t);
	size_t			start = 0;
	size_t			end = date.find("-");
	int				date_info;
	std::cout << date.substr(0, date.find("-")) << std::endl;
	std::cout << date.substr(date.find("-") + 1, date.find("-", date.find("-") + 1)) << std::endl;
	for (int i = 0; i < 3; i++)
	{
		if (end == std::string::npos)
			return (false);
		std::string str(date.substr(start, end));
		for(int ctr = 0; str[ctr]; ctr++)
		{
			if (!isdigit(str[ctr])){
			std::cout << str << std::endl; std::cout << "lol3" << std::endl; return (false);}
		}
		std::istringstream iss(str);
		iss >> date_info;
		if (!i && date_info > (info->tm_year + 1900)){
			std::cout << "lol" << std::endl; return (false);}
		if (i == 1 && (date_info < 1 || date_info > 12)){
			std::cout << "lol1" << std::endl; return (false);}
		if (i == 2 && (date_info < 1 || date_info > 31)){
			std::cout << "lol2" << std::endl; return (false);}
		start = end + 1;
		end = date.find("-", start);
		if (i == 2)
			end = date.size();
	}
	return (true);
}

void BitcoinExchange::printExchange(std::string input)
{
	std::string		line;
	std::ifstream	file(input);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		exit(1);
	}
	std::getline(file, line);
	if (line.compare("date | value"))
	{
		std::cerr << "Error: wrong formatting." << std::endl;
		exit(1);
	}
	while (file.is_open())
	{
		std::getline(file, line);
		if (line.empty() || file.eof())
			file.close();
		else
		{
			std::string date	= line.substr(0, line.find("|"));
			std::string s_val	= line.substr(line.find("|") + 1, line.size());
			if (!isValidDate(date))
				std::cout << "bad input => " << date << std::endl;
		}
	}
}