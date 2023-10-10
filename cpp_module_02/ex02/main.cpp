/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:10:46 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/10 12:03:14 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
	Fixed a(5);
	Fixed b(6);

	std::cout << "a value: " << a << std::endl;
	std::cout << "b value: " << b << std::endl;
	a++;
	std::cout << "a value: " << a << std::endl;
	std::cout << "b value: " << ++b << std::endl;
	std::cout << "a value: " << --a << std::endl;
	b--;
	std::cout << "b value: " << b << std::endl;
	std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;
	a = Fixed(100);
	if (a > b)
		std::cout << "a is greater than b" << std::endl;
	a = Fixed(1);
	if (a < b)
		std::cout << "a is less than b" << std::endl;
	a = Fixed(6);
	if (a == b)
		std::cout << "a is equals to b" << std::endl;
	return (0);
}
