/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:31:16 by ekoljone          #+#    #+#             */
/*   Updated: 2023/09/27 12:49:19 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main()
{
	Phonebook phone_book;

	std::cout << "\"ADD\" to save a new contact" << std::endl 
			<< "\"SEARCH\" to display a specifit contact" << std::endl
			<< "\"EXIT\" to exit" << std::endl;
	while (1)
	{
		std::cout << "> ";
		phone_book.get_user_input();
	}
	return (0);
}
