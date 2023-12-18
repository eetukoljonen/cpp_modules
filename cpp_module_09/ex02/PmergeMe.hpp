/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:32:33 by ekoljone          #+#    #+#             */
/*   Updated: 2023/12/18 18:15:41 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <iostream>
#include <list>
#include <sstream>
#include <vector>
#include <algorithm>

class PmergeMe
{
public:
	static	void				mergeInsertionSort(char **input);
private:
	static	std::list<int>		_list;
	static	std::vector<int>	_vector;
	static	void				parseInput(char **input);
	static	std::vector<int>	*createPairs();
	static	void				mergeSort(std::vector<int> &vector);
	static	void				binaryInsertionSort();
	static	void				sort();
	PmergeMe					&operator=(PmergeMe const &rhs);
	PmergeMe();
	PmergeMe(PmergeMe const &cpy);
	~PmergeMe();
};

void	exitProgram(std::string const &msg);
bool	isNumber(std::string str);

#endif
