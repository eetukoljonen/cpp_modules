/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:12:49 by ekoljone          #+#    #+#             */
/*   Updated: 2023/09/25 14:49:37 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook() : contact_index(0), contact_amount(0)
{}

void	Phonebook::get_user_input(void)
{
	std::string input;
	readinputline(input);
	if (!input.compare("EXIT"))
	{
		std::cout << "Goodbye!" << std::endl;
		exit(0);
	}
	if (!input.compare("ADD"))
		add();
	else if (!input.compare("SEARCH"))
	{	
		if (contact_amount == 0)
			std::cout << "No contacts in the phonebook!" << std::endl;
		else
			search();
	}
	
}

void Phonebook::add()
{
	Contact new_contact = Contact::set_contact_info();
	contacts[contact_index] = new_contact;
	contact_index = (contact_index + 1) % 8;
	if (contact_amount < 8)
		contact_amount++;
}

static std::string truncate(std::string const&str, int width)
{
	if (str.length() > 10)
		return (str.substr(0, width - 1) + ".");
	return (str);
}

void Phonebook::search()
{
	const int	width = 10;
	int			index;
	std::string	input;

	for (int i = 0; i < contact_amount; i++)
	{
		std::cout << std::setw(width) << std::right << i << '|'
			<< std::setw(width) << std::right << truncate(contacts[i].get_first_name(), width) << '|'
			<< std::setw(width) << std::right << truncate(contacts[i].get_last_name(), width) << '|'
			<< std::setw(width) << std::right << truncate(contacts[i].get_nickname(), width) << std::endl;
	}
	std::cout << "Contact index: ";
	readinputline(input);
	try {index = stoi(input);}
	catch (...) {index = -1;}
	if (index < 0 || index > contact_amount - 1)
		std::cout << "Index out of scope!" << std::endl;
	else
	{
		std::cout << contacts[index].get_first_name() << std::endl
			<< contacts[index].get_last_name() << std::endl
			<< contacts[index].get_nickname() << std::endl
			<< contacts[index].get_phone_number() << std::endl
			<< contacts[index].get_darkest_secret() << std::endl;
	}
}
