/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:03:17 by ekoljone          #+#    #+#             */
/*   Updated: 2023/12/15 16:50:56 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, float> BitcoinExchange::_data;

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &cpy)
{
	(void)cpy;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	(void)rhs;
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
	if (line.compare("date,exchange_rate"))
	{
		std::cerr << "Error: wrong formatting" << std::endl;
		exit(1);
	}
	while (file.is_open())
	{
		std::getline(file, line);
		if (line.empty() || file.eof())
			file.close();
		if (!line.empty())
		{
			if (line.find(",") == std::string::npos)
			{
				std::cerr << "Error: wrong formatting" << std::endl;
				exit(1);
			}
			std::string date	= line.substr(0, line.find(","));
			std::string s_val	= line.substr(line.find(",") + 1, line.size());
			std::istringstream	iss(s_val);
			float value;
			iss >> value;
			_data[date] = value;
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
	for (int i = 0; i < 3; i++)
	{
		if (end == std::string::npos)
			return (false);
		std::string str(date.substr(start, end - start));
		for(int ctr = 0; str[ctr]; ctr++)
		{
			if (!isdigit(str[ctr]))
				return (false);
		}
		std::istringstream iss(str);
		iss >> date_info;
		if (!i && date_info > (info->tm_year + 1900))
			return (false);
		if (i == 1 && (date_info < 1 || date_info > 12))
			return (false);
		if (i == 2 && (date_info < 1 || date_info > 31))
			return (false);
		start = end + 1;
		end = date.find("-", start);
		if (i == 1)
			end = date.size();
	}
	return (true);
}

bool isValidValue(std::string value)
{
	if (value.empty())
	{
		std::cout << "Error: number is missing" << std::endl;
		return (false);
	}
	for(int i = 0; value[i]; i++)
	{
		if (value[i] != '-' && value[i] != '+' && value[i] != '.' && !isdigit(value[i]))
		{
			std::cout << value << value.size() << std::endl;
			std::cout << "Error: not a number" << std::endl;
			return (false);
		}
	}
	long long				number;
	std::istringstream	iss(value);
	iss >> number;
	if (number > 1000)
	{
		std::cout << "Error: too large a number" << std::endl;
		return (false);
	}
	if (number < 0)
	{
		std::cout << "Error: not a positive number" << std::endl;
		return (false);
	}
	return (true);
}

std::map<std::string, float>::const_iterator closestDate(std::string const &date, std::map<std::string, float> const &_data)
{
	std::map<std::string, float>::const_iterator it = _data.upper_bound(date);
	if (it == _data.begin())
		return (_data.end());
	--it;
	return (it);
}

void BitcoinExchange::printDates(std::string &line)
{
	std::string date	= line.substr(0, line.find("|"));
	std::string s_val	= line.substr(line.find("|") + 1, line.size());
	if (!isValidDate(date))
		std::cout << "bad input => " << date << std::endl;
	else
	{
		if (isValidValue(s_val))
		{
			std::istringstream iss(s_val);
			float value;
			iss >> value;
			if (closestDate(date, _data) == _data.end())
				std::cout << "Error: date is too low" << std::endl;
			else
				std::cout << date
					<< " => " << value << " = "
					<< value * closestDate(date, _data)->second << std::endl;
		}
	}
}

void BitcoinExchange::printExchange(std::string input)
{
	std::string		line;
	std::ifstream	file(input);
	parseData();
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		exit(1);
	}
	std::getline(file, line);
	line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
	if (line.compare("date|value"))
	{
		std::cerr << "Error: wrong formatting." << std::endl;
		exit(1);
	}
	while (file.is_open())
	{
		std::getline(file, line);;
		line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
		if (line.empty() || file.eof())
			file.close();
		if (!line.empty())
			printDates(line);
	}
}
