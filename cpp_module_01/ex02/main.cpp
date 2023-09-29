/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:27:11 by ekoljone          #+#    #+#             */
/*   Updated: 2023/09/28 15:36:26 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "Memory address of string: " << &string << std::endl
		<< "Memory address of stringPTR: " << stringPTR << std::endl
		<< "Memory address of stringREF: " << &stringREF << std::endl << std::endl;
	
	std::cout << "Value of string: " << string << std::endl
		<< "Value pointed by stringPTR: " << *stringPTR << std::endl
		<< "Value pointed by stringREF: " << stringREF << std::endl;
	return (0);
}
