/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:13:29 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/11 12:18:01 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap John("John");
	John.attack("Kalle");
	John.takeDamage(9);
	John.beRepaired(1);

	std::cout << std::endl;

	ScavTrap Marko("Marko");
	Marko.attack("Jouni");
	Marko.takeDamage(90);
	Marko.guardGate();

	std::cout << std::endl;
	
	return (0);
}