/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:22:02 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/24 15:27:11 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	ScalarConverter::convert(argv[1]);
	return (0);
}