/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:32:33 by ekoljone          #+#    #+#             */
/*   Updated: 2023/12/19 14:55:34 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <iostream>
#include <deque>
#include <sstream>
#include <vector>
#include <algorithm>

class PmergeMe
{
public:
	static	void				mergeInsertionSort(char **input);
private:
	static	std::deque<int>		_deque;
	static	std::vector<int>	_vector;
	static	double				_vecDuration;
	static	double				_deqDuration;
	static	unsigned int		_inputSize;
	//sorting functions for deque
	static	std::deque<int>		*createPairsDeq();
	static	void				parseInputDeq(char **input);
	static	void				mergeSortDeq(std::deque<int> &list);
	static	void				binaryInsertionSortDeq(std::deque<int> *pairs);
	static	void				sortDeq(char **input);
	//sorting functions for vector
	static	std::vector<int>	*createPairsVec();
	static	void				parseInputVector(char **input);
	static	void				mergeSortVec(std::vector<int> &vector);
	static	void				binaryInsertionSortVec(std::vector<int> *pairs);
	static	void				sortVec(char **input);

	PmergeMe					&operator=(PmergeMe const &rhs);
	PmergeMe();
	PmergeMe(PmergeMe const &cpy);
	~PmergeMe();
};

template<typename T>
void printContainer(T &vector)
{
	typename T::iterator it = vector.begin();
	typename T::iterator ite = vector.end();
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}
void	exitProgram(std::string const &msg);
bool	isNumber(std::string str);
void	printInput(char **input);

#endif
