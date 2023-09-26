/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:58:48 by ekoljone          #+#    #+#             */
/*   Updated: 2023/09/26 14:12:06 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACT_HPP__
#define __CONTACT_HPP__
#include <iostream>
#include <string>

class Contact
{
public:
	static Contact set_contact_info(void);
	static void	get_info(std::string &info, std::string instruction);
	std::string const&get_first_name(void) const;
	std::string const&get_last_name(void) const;
	std::string const&get_nickname(void) const;
	std::string const&get_phone_number(void) const;
	std::string const&get_darkest_secret(void) const;

private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
};

void	readinputline(std::string &input);

#endif