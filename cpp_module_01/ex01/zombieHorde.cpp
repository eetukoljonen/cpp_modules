/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:33:03 by ekoljone          #+#    #+#             */
/*   Updated: 2023/09/28 15:20:24 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string const name)
{
	Zombie *zombieHorde;
	try
	{
		zombieHorde = new Zombie[N];
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << e.what() << std::endl;
		exit(1);
	}
	for (int i = 0; i < N; i++)
		zombieHorde[i].set_name(name);
	return (zombieHorde);
}
