/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:56:30 by ekoljone          #+#    #+#             */
/*   Updated: 2023/12/14 17:48:03 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOINEXHANGE_HPP__
#define __BITCOINEXHANGE_HPP__

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &cpy);
	~BitcoinExchange();
	BitcoinExchange					&operator=(BitcoinExchange const &rhs);
	void							printExchange(std::string);
private:
	std::map<std::string, float>	_data;
	void 							parseData();
};

#endif