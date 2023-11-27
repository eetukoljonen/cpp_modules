/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:34:36 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/27 17:46:16 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data		data1;
	data1.x		= 10;
	data1.y		= 20;
	data1.c		= 'a';

	std::cout	<< "data1.x = " << data1.x << ", data1.y = "
				<< data1.y << ", data1.c = " << data1.c << std::endl;

	uintptr_t	uiptr;

	uiptr = Serializer::serialize(&data1); // converting data1 to uintptr_r

	std::cout << "data1 address represented as an unsigned int = " << uiptr << std::endl;
	std::cout << "uiptr value converted to hex = " << std::hex << uiptr << std::endl << std::dec;

	Data *data2 = Serializer::deserialize(uiptr); // converting uiptr back to data pointer

	std::cout	<< "address of data1 = " << &data1
				<< ", address of data2 = " << data2 << std::endl;

	std::cout	<< "data2->x = " << data2->x << ", data2->y = "
				<< data2->y << ", data2->c = " << data2->c << std::endl;
	return (0);
}