/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:50:30 by ekoljone          #+#    #+#             */
/*   Updated: 2023/09/29 13:51:22 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileManipulation.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "try ./sed <filename> <str_to_replace> <str_to_replace_with>" << std::endl;
		return (1);
	}
	FileManipulation test(argv[1], argv[2], argv[3]);
	test.replaceFile();
	return (0);
}
