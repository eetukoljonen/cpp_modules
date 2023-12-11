/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:08:56 by ekoljone          #+#    #+#             */
/*   Updated: 2023/12/11 12:55:18 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int int_arr[3] = {1, 2, 3};
	::iter(int_arr, 3, print_element<int>);
	std::cout << std::endl;

	float float_arr[3] = {1.3f, 2.4f, 3.6f};
	::iter(float_arr, 3, print_element<float>);
	std::cout << std::endl;

	char str[4] = "abc";
	::iter(str, 3, print_element<char>);
	std::cout << std::endl;

	int const const_arr[3] = {7, 8, 9};
	::iter(const_arr, 3, print_element<int const>);
	return (0);
}