/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:53:15 by ekoljone          #+#    #+#             */
/*   Updated: 2023/09/28 18:07:30 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon) : type(weapon) {}

Weapon::~Weapon() {}

std::string const&Weapon::getType(void) const
{
	return (this->type);
}

void Weapon::setType(std::string const new_type)
{
	type = new_type;
}
