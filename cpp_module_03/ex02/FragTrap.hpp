/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:20:58 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/11 12:25:53 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap &cpy);
	~FragTrap();
	FragTrap	&operator=(FragTrap &rhs);
	void	attack(std::string const &target);
	void	highFivesGuys();
private:
	std::string	_name;
	int			HitPoints;
	int			EnergyPoints;
	int			AttackDamage;
};


#endif