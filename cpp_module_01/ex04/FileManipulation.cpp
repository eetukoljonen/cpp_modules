/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileManipulation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:23:24 by ekoljone          #+#    #+#             */
/*   Updated: 2023/09/29 13:45:58 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileManipulation.hpp"

FileManipulation::FileManipulation(std::string filename, std::string to_be_replaced, std::string to_replace_with)
	: _filename(filename), _to_be_replaced(to_be_replaced), _to_replace_with(to_replace_with) {}

FileManipulation::~FileManipulation(){}

void	FileManipulation::replaceFile(void)
{
	if (!_to_be_replaced.compare(""))
		return ;
	open_fstreams();
	while (!ifs.eof())
	{
		std::string line = getNextLine();
		replace_line(line);
		ofs << line;
		if (!ifs.eof())
			ofs << std::endl;
	}
	ifs.close();
	ofs.close();
}

void	FileManipulation::replace_line(std::string &line)
{
	size_t i = 0;
	while (i != std::string::npos)
	{
		i = line.find(_to_be_replaced, i);
		if (i != std::string::npos)
		{
			line.erase(i, _to_be_replaced.length());
			line.insert(i, _to_replace_with);
			i += _to_replace_with.length();
		}
	}
}

void	FileManipulation::open_fstreams(void)
{
	ifs.open(_filename);
	if (!ifs.is_open())
	{
		std::cerr << _filename << " couldn't be opened" << std::endl;
		exit(1);
	}
	ofs.open("result");
	if (!ofs.is_open())
	{
		std::cerr << "result couldn't be opened" << std::endl;
		exit(1);
	}	
}

std::string	FileManipulation::getNextLine(void)
{
	std::string nextLine;
	getline(ifs, nextLine);
	return (nextLine);
}
