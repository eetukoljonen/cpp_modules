/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:02:22 by ekoljone          #+#    #+#             */
/*   Updated: 2023/09/25 14:50:01 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::get_info(std::string &info, std::string instruction)
{
	std::cout << instruction;
	readinputline(info);
	while (info.empty())
	{
		std::cout << "This cannot be left empty! " << instruction;
		readinputline(info);
	}
}

Contact Contact::set_contact_info(void)
{
	Contact new_contact;

	get_info(new_contact.first_name, "Enter first name: ");
	get_info(new_contact.last_name, "Enter last name: ");
	get_info(new_contact.nickname, "Enter nickname: ");
	get_info(new_contact.phone_number, "Enter phone number: ");
	get_info(new_contact.darkest_secret, "Enter darkest secret: ");
	return (new_contact);
}

std::string const&Contact::get_first_name(void) const
{
	return first_name;
}

std::string const&Contact::get_last_name(void) const
{
	return last_name;
}

std::string const&Contact::get_nickname(void) const
{
	return nickname;
}

std::string const&Contact::get_phone_number(void) const
{
	return phone_number;
}

std::string const&Contact::get_darkest_secret(void) const
{
	return darkest_secret;
}

void	readinputline(std::string &input)
{
	std::getline(std::cin, input);
	if (std::cin.eof())
	{
		std::cout << "Goodbye!" << std::endl;
		exit(0);
	}
}