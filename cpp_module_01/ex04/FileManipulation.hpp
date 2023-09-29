/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileManipulation.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:16:45 by ekoljone          #+#    #+#             */
/*   Updated: 2023/09/29 13:51:26 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILEMANIPULATION_HPP__
#define __FILEMANIPULATION_HPP__
#include <iostream>
#include <algorithm>
#include <fstream>
class FileManipulation
{
public:
	FileManipulation(std::string filename, std::string to_be_replaced, std::string to_replace_with);
	~FileManipulation();
	void			replaceFile(void);
private:
	void			replace_line(std::string &line);
	void			open_fstreams(void);
	std::string		getNextLine(void);
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		_filename;
	std::string		_to_be_replaced;
	std::string		_to_replace_with;
};

#endif