/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:13:29 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/18 12:43:12 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap Janne("Janne");
	ClapTrap John("John");
	Janne.attack("Kalle");
	John.attack("Janne");
	John.takeDamage(9);
	John.beRepaired(1);
	ClapTrap Copy = John;
	Copy.beRepaired(5);
	return (0);
}