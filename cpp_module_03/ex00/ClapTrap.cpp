/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 09:23:38 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/18 12:43:36 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "ClapTrap Default constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "ClapTrap Param constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &cpy)
{
	std::cout << "ClapTrap Copy constructor has been called" << std::endl;
	this->_name = cpy._name;
	this->HitPoints = cpy.HitPoints;
	this->EnergyPoints = cpy.EnergyPoints;
	this->AttackDamage = cpy.AttackDamage;
}

ClapTrap &ClapTrap::operator=(ClapTrap &rhs)
{
	std::cout << "ClapTrap Copy assigment operator has been called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->HitPoints = rhs.HitPoints;
		this->EnergyPoints = rhs.EnergyPoints;
		this->AttackDamage = rhs.AttackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(std::string const &target)
{
	if (HitPoints <= 0 || EnergyPoints <= 0)
		return ;
	std::cout << "ClapTrap " << this->_name << " attacks "
		<< target << ", causing " << AttackDamage
		<< " points of damage!" << std::endl;
	this->EnergyPoints -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (HitPoints <= 0)
		return ;
	std::cout << this->_name << " has been attacked, causing to lose " << amount
		<< " points of health!" << std::endl;
	this->HitPoints -= amount;
	if (HitPoints < 0)
		HitPoints = 0;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (HitPoints <= 0 || EnergyPoints <= 0)
		return ;
	std::cout << this->_name << " got repaired, causing to gain " << amount
		<< " points of health!" << std::endl;
	this->HitPoints += amount;
	this->EnergyPoints -= 1;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor has been called" << std::endl;
}
