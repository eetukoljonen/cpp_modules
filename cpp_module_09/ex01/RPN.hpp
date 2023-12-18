/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:53:00 by ekoljone          #+#    #+#             */
/*   Updated: 2023/12/18 13:25:21 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <stack>
#include <iostream>
#include <sstream>

class RPN
{
public:	
	static void					ReversePolishNotation(std::string input);
private:
	static std::stack<float>	_stack;
	static void					doOperations(std::string const &number);
	RPN							&operator=(const RPN &rhs);
	RPN();
	RPN(const RPN &cpy);
	~RPN();
};

bool	isNumber(std::string str);
void	exitProgram();

#endif
