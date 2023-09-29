/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:16:41 by ekoljone          #+#    #+#             */
/*   Updated: 2023/09/28 18:15:22 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

HumanB::~HumanB(){}

void HumanB::attack(void) const
{
	if (weapon)
		std::cout << this->name << " attack with their "
			<< this->weapon->getType() << std::endl;
	else
		std::cout << this->name
			<< " don't have a weapon to attack with" << std::endl;
	
}

void HumanB::setWeapon(Weapon &new_weapon)
{
	this->weapon = &new_weapon;
}