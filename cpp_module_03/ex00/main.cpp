/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:13:29 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/10 16:54:56 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class ClapTrap
{
public:
	ClapTrap() : _name("Default"), HitPoints(10), EnergyPoints(10), AttackDamage(10)
	{
		std::cout << "ClapTrap " << this->_name << " has been created" << std::endl;
	}
	ClapTrap(std::string name) : _name(name), HitPoints(10), EnergyPoints(10), AttackDamage(10)
	{
		std::cout << "ClapTrap " << this->_name << " has been created" << std::endl;
	}
	ClapTrap(ClapTrap const &cpy)
	{
		std::cout << "Copy constructor has been called" << std::endl;
		this->_name = cpy._name;
		this->HitPoints = cpy.HitPoints;
		this->EnergyPoints = cpy.EnergyPoints;
		this->AttackDamage = cpy.AttackDamage;
	}
	ClapTrap &operator=(ClapTrap &rhs)
	{
		if (this != &rhs)
		{
			this->_name = rhs._name;
			this->HitPoints = rhs.HitPoints;
			this->EnergyPoints = rhs.EnergyPoints;
			this->AttackDamage = rhs.AttackDamage;
		}
		return (*this);
	}
	void	attack(std::string const &target)
	{
		if (HitPoints <= 0 || EnergyPoints <= 0)
			return ;
		std::cout << "ClapTrap " << this->_name << " attacks "
			<< target << ", causing " << AttackDamage
			<< " points of damage!" << std::endl;
		this->EnergyPoints -= 1;
	}
	void	takeDamage(unsigned int amount)
	{
		if (HitPoints <= 0)
			return ;
		std::cout << "ClapTrap " << this->_name << " has been attacked, causing to lose " << amount
			<< " points of health!" << std::endl;
		this->HitPoints -= amount;
	}
	void	beRepaired(unsigned int amount)
	{
		if (HitPoints <= 0 || EnergyPoints <= 0)
			return ;
		std::cout << "ClapTrap " << this->_name << " got repaired, causing to gain " << amount
			<< " points of health!" << std::endl;
		this->HitPoints += amount;
		this->EnergyPoints -= 1;
	}
	~ClapTrap()
	{
		std::cout << "ClapTrap " << this->_name << " has been destroyed" << std::endl;
	}
private:
	std::string	_name;
	int			HitPoints;
	int			EnergyPoints;
	int			AttackDamage;
};

int main()
{
	ClapTrap Janne;
	Janne.attack("Kalle");
	ClapTrap John("John");
	John.attack("Kalle");
	John.takeDamage(9);
	John.beRepaired(1);
	ClapTrap Copy = John;
	return (0);
}