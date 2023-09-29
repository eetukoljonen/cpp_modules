/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:46:34 by ekoljone          #+#    #+#             */
/*   Updated: 2023/09/28 18:07:56 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__
#include <iostream>

class Weapon
{
public:
	Weapon(std::string weapon);
	~Weapon();
	std::string const &getType(void) const;
	void setType(std::string const new_type);
private:
	std::string type;
};

#endif