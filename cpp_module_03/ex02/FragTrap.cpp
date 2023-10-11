/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:26:13 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/11 12:28:04 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap Default constructor has been called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap String constructor has been called" << std::endl;
	this->_name = name;
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
}

FragTrap::FragTrap(FragTrap &cpy) : ClapTrap(cpy._name)
{
	std::cout << "FragTrap Copy constructor has been called" << std::endl;
	this->_name = cpy._name;
	this->HitPoints = cpy.HitPoints;
	this->EnergyPoints = cpy.EnergyPoints;
	this->AttackDamage = cpy.AttackDamage;
}

void	FragTrap::attack(std::string const &target)
{
	if (HitPoints <= 0 || EnergyPoints <= 0)
		return ;
	std::cout << "FragTrap " << this->_name << " attacks "
		<< target << ", causing " << AttackDamage
		<< " points of damage!" << std::endl;
	this->EnergyPoints -= 1;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << " requests high fives!" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap &rhs)
{
	std::cout << "FragTrap Copy assigment operator has been called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->HitPoints = rhs.HitPoints;
		this->EnergyPoints = rhs.EnergyPoints;
		this->AttackDamage = rhs.AttackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor has been called" << std::endl;
}
