/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:57:21 by ekoljone          #+#    #+#             */
/*   Updated: 2023/09/27 12:50:09 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	std::string	str;
	int			i;
	int			ctr;

	i = 0;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (argv[++i])
	{
		str = argv[i];
		ctr = -1;
		while (str[ctr++])
			str[ctr] = toupper(str[ctr]);
		std::cout << str;
	}
	std::cout << std::endl;
	return (0);
}
