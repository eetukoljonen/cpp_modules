/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:16:39 by ekoljone          #+#    #+#             */
/*   Updated: 2023/09/26 14:11:55 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_HPP__
#define __PHONEBOOK_HPP__
#include "Contact.hpp"
#include <iomanip>

class Phonebook
{
public:
	Phonebook(void);
	void	get_user_input(void);
private:
	int		contact_amount;
	int		contact_index;
	void	add(void);
	void	search(void);
	Contact contacts[8];
};

#endif