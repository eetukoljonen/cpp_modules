/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:01:30 by ekoljone          #+#    #+#             */
/*   Updated: 2023/09/28 18:15:30 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &new_weapon)
	: name(name), weapon(new_weapon) {}

HumanA::~HumanA(void){}

void HumanA::attack(void) const
{
	std::cout << this->name << " attack with their "
		<< this->weapon.getType() << std::endl;
	
}
