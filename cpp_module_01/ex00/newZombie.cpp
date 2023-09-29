/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:47:46 by ekoljone          #+#    #+#             */
/*   Updated: 2023/09/28 15:20:20 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie *new_zombie;
	try
	{
		new_zombie = new Zombie(name);
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << e.what() << std::endl;
		exit(1);
	}
	return (new_zombie);
}
