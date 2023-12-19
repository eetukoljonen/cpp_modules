/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:56:30 by ekoljone          #+#    #+#             */
/*   Updated: 2023/12/19 16:30:16 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOINEXHANGE_HPP__
#define __BITCOINEXHANGE_HPP__

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange
{
public:
	static void									printExchange(std::string);
private:
	static std::map<std::string, float>			_data;
	static void 								parseData();
	static void									printDates(std::string &line);
	BitcoinExchange								&operator=(BitcoinExchange const &rhs);
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &cpy);
	~BitcoinExchange();
};

std::map<std::string, float>::const_iterator	closestDate(std::string const &date, std::map<std::string, float> const &_data);
bool											isValidValue(std::string value);
bool											isValidDate(std::string date);
void											exitProgram(std::string const &msg);

#endif