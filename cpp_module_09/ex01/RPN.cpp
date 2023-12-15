/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:54:24 by ekoljone          #+#    #+#             */
/*   Updated: 2023/12/15 18:27:48 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<int> RPN::_stack;

RPN::RPN(){}

RPN::RPN(RPN const &cpy){(void)cpy;}

RPN::~RPN(){}

RPN &RPN::operator=(RPN const &rhs)
{
    (void)rhs;
    return (*this);
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

void	RPN::doOperations(std::string const &number)
{
	int result = _stack.top();
	_stack.pop();
	if (!number.compare("*"))
		result *= _stack.top();
	else if (!number.compare("/"))
		result = _stack.top() / result;
	else if (!number.compare("-"))
		result = _stack.top() - result;
	else if (!number.compare("+"))
		result = _stack.top() + result;
	else
	{
		std::cerr << "Error" << std::endl;
		exit(0);
	}
	_stack.pop();
	_stack.push(result);
}

void	RPN::ReversePolishNotation(std::string input)
{
	int		value;
	size_t	start = 0;
	size_t	end = 0;
	while (end != input.size())
	{
		end = input.find(" ", start);
		if (end == std::string::npos)
			end = input.size();
		std::string number = input.substr(start, end - start);
		start = end + 1;
		std::istringstream iss(number);
		if (_stack.size() <= 1 && !isNumber(number))
		{
			std::cerr << "Error" << std::endl;
			return ;
		}
		if (_stack.size() >= 2 && !isNumber(number))
			doOperations(number);
		else
		{
			iss >> value;
			_stack.push(value);
		}
	}
	if (_stack.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		return ;
	}
	std::cout << _stack.top() << std::endl;
}
