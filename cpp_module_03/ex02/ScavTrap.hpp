/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:55:15 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/11 12:52:42 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap &cpy);
	~ScavTrap();
	ScavTrap	&operator=(ScavTrap &rhs);
	void	attack(std::string const &target);
	void	guardGate();
private:
	std::string	_name;
	int			HitPoints;
	int			EnergyPoints;
	int			AttackDamage;
};

#endif