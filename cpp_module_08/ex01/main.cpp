/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:09:05 by ekoljone          #+#    #+#             */
/*   Updated: 2023/12/12 14:27:24 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl << std::endl;

//-------------------------------------------------------------------//

	Span sp1 = Span(100000);
	for (int i = 0; i < 100000; i++)
		sp1.addNumber(i);
	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl;
	try
	{
		sp1.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
//-------------------------------------------------------------------//

	Span sp2(1);
	sp2.addNumber(1);
	try
	{
		std::cout << sp2.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
//-------------------------------------------------------------------//

	srand(time(0));
	std::vector<int> vector;
	for (int i = 0; i < 500; i++)
		vector.push_back(rand());
	Span sp3(500);
	sp3.addRange< std::vector<int> >(vector.begin(), vector.end());
	std::cout << sp3.shortestSpan() << std::endl;
}
