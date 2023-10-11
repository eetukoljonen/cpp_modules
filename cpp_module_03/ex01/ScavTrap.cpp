/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:42:38 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/11 11:42:40 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap Default constructor has been called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap String constructor has been called" << std::endl;
	this->_name = name;
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap &cpy) : ClapTrap(cpy._name)
{
	std::cout << "ScavTrap Copy constructor has been called" << std::endl;
	this->_name = cpy._name;
	this->HitPoints = cpy.HitPoints;
	this->EnergyPoints = cpy.EnergyPoints;
	this->AttackDamage = cpy.AttackDamage;
}

void	ScavTrap::attack(std::string const &target)
{
	if (HitPoints <= 0 || EnergyPoints <= 0)
		return ;
	std::cout << "ScavTrap " << this->_name << " attacks "
		<< target << ", causing " << AttackDamage
		<< " points of damage!" << std::endl;
	this->EnergyPoints -= 1;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap &rhs)
{
	std::cout << "ScavTrap Copy assigment operator has been called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->HitPoints = rhs.HitPoints;
		this->EnergyPoints = rhs.EnergyPoints;
		this->AttackDamage = rhs.AttackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor has been called" << std::endl;
}
