/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:37:01 by ekoljone          #+#    #+#             */
/*   Updated: 2023/12/20 12:34:20 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::deque<int>		PmergeMe::_deque;
std::vector<int>	PmergeMe::_vector;
double				PmergeMe::_vecDuration;
double				PmergeMe::_deqDuration;
unsigned int		PmergeMe::_inputSize;


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
	for (int i = 0; str[i]; i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

void PmergeMe::parseInputVector(char **input)
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
		_vector.push_back(static_cast<int>(value));
	}
	_inputSize = _vector.size();
}

void sortPairVec(std::vector<int> &pair)
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

void PmergeMe::binaryInsertionSortVec(std::vector<int> *pairs)
{
	unsigned int pair_count;
	if (_inputSize % 2)
		pair_count = _inputSize / 2 + 1;
	else
		pair_count = _inputSize / 2;
	for (unsigned int i = 0; i < pair_count; i++)
	{
		std::vector<int>::iterator it = std::lower_bound(_vector.begin(), _vector.end(),  pairs[i][0]);
		if (pairs[i].size() == 2)
			_vector.insert(it, pairs[i][0]);
	}
}

void mergeVec(std::vector<int> &leftArray, std::vector<int> &rightArray,
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

void PmergeMe::mergeSortVec(std::vector<int> &array)
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
	mergeSortVec(leftArray);
	mergeSortVec(rightArray);
	mergeVec(leftArray, rightArray, array);
}

std::vector<int> *PmergeMe::createPairsVec()
{
	std::vector<int> *pairs;
	std::vector<int> tmp(_vector);
	unsigned int pair_count;
	if (_inputSize % 2)
		pair_count = tmp.size() / 2 + 1;
	else
		pair_count = tmp.size() / 2;
	pairs = new std::vector<int>[pair_count];
	std::vector<int>::iterator it = tmp.begin();
	std::vector<int>::iterator ite = tmp.end();
	_vector.clear();
	int pair_i = 0;
	while (it != ite)
	{
		for (int i = 0; i < 2 && it != ite; i++)
		{
			pairs[pair_i].push_back(*it);
			it++;
		}
		sortPairVec(pairs[pair_i]);
		_vector.push_back(pairs[pair_i].back());
		pair_i++;
	}
	return (pairs);
}

void PmergeMe::sortVec(char **input)
{
	clock_t vectorStart = clock();
	parseInputVector(input);
	std::vector<int> *pairs = createPairsVec();
	mergeSortVec(_vector);
	binaryInsertionSortVec(pairs);
	clock_t vectorEnd = clock();
	_vecDuration = (double)(vectorEnd - vectorStart) / CLOCKS_PER_SEC * 1000000;
	std::cout << "std::vector<int> Before: ";
	printInput(input);
	std::cout << "std::vector<int> After: ";
	printContainer(_vector);
	delete [] pairs;
}

void sortPairDeq(std::deque<int> &pair)
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

void PmergeMe::parseInputDeq(char **input)
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
		_deque.push_back(static_cast<int>(value));
	}
	_inputSize = _deque.size();
}

void mergeDeq(std::deque<int> &leftArray, std::deque<int> &rightArray,
			std::deque<int> &array)
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

void PmergeMe::mergeSortDeq(std::deque<int> &array)
{
	size_t length = array.size();
	if (length <= 1)
		return ;
	size_t middle = length / 2;
	std::deque<int> leftArray;
	std::deque<int> rightArray;
	for (size_t i = 0; i < length; i++)
	{
		if (i < middle)
			leftArray.push_back(array[i]);
		else
			rightArray.push_back(array[i]);
	}
	mergeSortDeq(leftArray);
	mergeSortDeq(rightArray);
	mergeDeq(leftArray, rightArray, array);
}

std::deque<int> *PmergeMe::createPairsDeq()
{
	std::deque<int> *pairs;
	std::deque<int> tmp(_deque);
	unsigned int pair_count;
	if (_inputSize % 2)
		pair_count = tmp.size() / 2 + 1;
	else
		pair_count = tmp.size() / 2;
	pairs = new std::deque<int>[pair_count];
	std::deque<int>::iterator it = tmp.begin();
	std::deque<int>::iterator ite = tmp.end();
	_deque.clear();
	int pair_i = 0;
	while (it != ite)
	{
		for (int i = 0; i < 2 && it != ite; i++)
		{
			pairs[pair_i].push_back(*it);
			it++;
		}
		sortPairDeq(pairs[pair_i]);
		_deque.push_back(pairs[pair_i].back());
		pair_i++;
	}
	return (pairs);
}

void PmergeMe::binaryInsertionSortDeq(std::deque<int> *pairs)
{
	unsigned int pair_count;
	if (_inputSize % 2)
		pair_count = _inputSize / 2 + 1;
	else
		pair_count = _inputSize / 2;
	for (unsigned int i = 0; i < pair_count; i++)
	{
		std::deque<int>::iterator it = std::lower_bound(_deque.begin(), _deque.end(),  pairs[i][0]);
		if (pairs[i].size() == 2)
			_deque.insert(it, pairs[i][0]);
	}
}

void printInput(char **input)
{
	for (int i = 1; input[i]; i++)
		std::cout << input[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::sortDeq(char **input)
{
	clock_t dequeStart = clock();
	parseInputDeq(input);
	std::deque<int> *pairs = createPairsDeq();
	mergeSortDeq(_deque);
	binaryInsertionSortDeq(pairs);
	clock_t dequeEnd = clock();
	_deqDuration = (double)(dequeEnd - dequeStart) / CLOCKS_PER_SEC * 1000000;
	std::cout << "std::deque<int> Before: ";
	printInput(input);
	std::cout << "std::deque<int> After: ";
	printContainer(_deque);
	delete [] pairs;
}

void PmergeMe::mergeInsertionSort(char **input)
{
	sortVec(input);
	sortDeq(input);
	std::cout	<< "Time to process a range of "
				<< _inputSize << " with std::deque<int> : "
				<< _deqDuration << " us" << std::endl;
	std::cout	<< "Time to process a range of "
				<< _inputSize << " with std::vector<int> : "
				<< _vecDuration << " us" << std::endl;
}
