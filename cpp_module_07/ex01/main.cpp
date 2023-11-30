/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:08:56 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/30 11:27:43 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int int_arr[3] = {1, 2, 3};

	std::cout << "int_arr before iter = ";
	::printArray<int>(int_arr, 3);

	::iter<int>(int_arr, 3, addOne);
	
	std::cout << "int_arr after iter = ";
	::printArray<int>(int_arr, 3);

	float float_arr[3] = {1.3f, 2.4f, 3.6f};

	std::cout << "float_arr before iter = ";
	::printArray<float>(float_arr, 3);

	::iter<float>(float_arr, 3, addOne);
	
	std::cout << "float_arr after iter = ";
	::printArray<float>(float_arr, 3);

	char str[4] = "abc";

	std::cout << "str before iter = ";
	::printArray<char>(str, 3);

	::iter<char>(str, 3, addOne);
	
	std::cout << "str after iter = ";
	::printArray<char>(str, 3);
	return (0);
}