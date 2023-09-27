/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:30:51 by ekoljone          #+#    #+#             */
/*   Updated: 2023/09/27 18:11:37 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__
#include <iostream>

class Zombie
{
public:
	Zombie();
	~Zombie(void);
	void set_name(std::string z_name);
	void announce(void);
private:
	std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
