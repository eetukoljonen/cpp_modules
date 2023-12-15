/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:53:00 by ekoljone          #+#    #+#             */
/*   Updated: 2023/12/15 18:27:47 by ekoljone         ###   ########.fr       */
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
	static void				ReversePolishNotation(std::string input);
private:
	static std::stack<int>	_stack;
	static void				doOperations(std::string const &number);
	RPN						&operator=(const RPN &rhs);
	RPN();
	RPN(const RPN &cpy);
	~RPN();
};

bool	isNumber(std::string str);

#endif
