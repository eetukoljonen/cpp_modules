/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:10:10 by ekoljone          #+#    #+#             */
/*   Updated: 2023/12/11 17:38:45 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <vector>

int main()
{
	std::list<int> list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	std::cout << easyfind(list, 3) << std::endl;

	std::vector<int> vector;
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);	
	std::cout << easyfind(vector, 4) << std::endl;

	try
	{
		std::cout << easyfind(vector, 6) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}