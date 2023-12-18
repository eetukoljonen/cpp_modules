/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:37:01 by ekoljone          #+#    #+#             */
/*   Updated: 2023/12/18 18:36:36 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::list<int>		PmergeMe::_list;
std::vector<int>	PmergeMe::_vector;


PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(PmergeMe const &cpy){(void)cpy;}

PmergeMe::~PmergeMe(){}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
    (void)rhs;
    return (*this);
}

void exitProgram(std::string const &msg)
{
	std::cout << "Error: " << msg << std::endl;
	exit(1);
}

bool isNumber(std::string str)
{
	if (str.size() == 1)
		return (isdigit(str[0]));
	bool sign = false;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (i == 0)
				sign = true;
			else
				return (false);
		}
		if (!isdigit(str[i]) && !sign)
			return (false);
	}
	return (true);
}

void PmergeMe::parseInput(char **input)
{
	long long value;
	if (!input[1])
		exitProgram("too few arguments");
	for (int i = 1; input[i]; i++)
	{
		if (!isNumber(input[i]))
			exitProgram("invalid argument");
		std::istringstream iss(input[i]);
		iss >> value;
		if (value > 2147483647 || value < -2147483648)
			exitProgram("invalid argument");
		_list.push_back(static_cast<int>(value));
	}
}

void printPair(std::vector<int> &pair)
{
	std::vector<int>::iterator it = pair.begin();
	std::vector<int>::iterator ite = pair.end();
	std::cout << "[";
	while (it != ite)
	{
		std::cout << *it;
		it++;
		if (it != ite)
			std::cout << " - ";
	}
	std::cout << "] " << std::endl;
}

void sortPair(std::vector<int> &pair)
{
	if (pair.size() == 1)
		return ;
	if (pair[0] > pair[1])
	{
		int tmp = pair[0];
		pair[0] = pair[1];
		pair[1] = tmp;
	}
}

// std::vector<int>::iterator binarySearch(std::vector<int> &array, int const &value)
// {
// 	std::vector<int>::iterator it = array.begin() + std::distance(array.begin(), array.end()) / 2;
// 	if (*it == value)
// 		return (it);
// 	size_t length = array.size();
// 	std::vector<int> tmpArray;
// 	for (size_t i = 0; i < length; i++)
// 	{
		
// 	}
// }

void PmergeMe::binaryInsertionSort()
{
	std::cout << *binarySearch(_vector, 8) << std::endl;
}

void merge(std::vector<int> &leftArray, std::vector<int> &rightArray,
			std::vector<int> &array)
{
	size_t leftSize = leftArray.size();
	size_t rightSize = rightArray.size();
	size_t i = 0, l = 0, r = 0;
	while (l < leftSize && r < rightSize)
	{
		if (leftArray[l] < rightArray[r])
			array[i++] = leftArray[l++];
		else
			array[i++] = rightArray[r++];
	}
	while (l < leftSize)
		array[i++] = leftArray[l++];
	while (r < rightSize)
		array[i++] = rightArray[r++];
}

void PmergeMe::mergeSort(std::vector<int> &array)
{
	size_t length = array.size();
	if (length <= 1)
		return ;
	size_t middle = length / 2;
	std::vector<int> leftArray;
	std::vector<int> rightArray;
	for (size_t i = 0; i < length; i++)
	{
		if (i < middle)
			leftArray.push_back(array[i]);
		else
			rightArray.push_back(array[i]);
	}
	mergeSort(leftArray);
	mergeSort(rightArray);
	merge(leftArray, rightArray, array);
}

std::vector<int> *PmergeMe::createPairs()
{
	std::vector<int> *pairs;
	unsigned int pair_count;
	if (_list.size() % 2)
		pair_count = _list.size() / 2 + 1;
	else
		pair_count = _list.size() / 2;
	pairs = new std::vector<int>[pair_count];
	std::list<int>::iterator it = _list.begin();
	std::list<int>::iterator ite = _list.end();
	int pair_i = 0;
	while (it != ite)
	{
		for (int i = 0; i < 2 && it != ite; i++)
		{
			pairs[pair_i].push_back(*it);
			it++;
		}
		sortPair(pairs[pair_i]);
		_vector.push_back(pairs[pair_i].back());
		printPair(pairs[pair_i]);
		pair_i++;
	}
	return (pairs);
}

void printVector(std::vector<int> &vector)
{
	std::vector<int>::iterator it = vector.begin();
	std::vector<int>::iterator ite = vector.end();
	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void PmergeMe::sort()
{
	std::vector<int> *pairs = createPairs();
	printVector(_vector);
	mergeSort(_vector);
	printVector(_vector);
	binaryInsertionSort();
	delete [] pairs;
}

void PmergeMe::mergeInsertionSort(char **input)
{
	parseInput(input);
	sort();
}
