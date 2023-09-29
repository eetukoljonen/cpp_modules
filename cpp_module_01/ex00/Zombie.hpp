/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:55:09 by ekoljone          #+#    #+#             */
/*   Updated: 2023/09/28 14:47:25 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__
#include <iostream>

class Zombie
{
public:
	Zombie(std::string name);
	~Zombie(void);
	void announce(void);
private:
	std::string name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif