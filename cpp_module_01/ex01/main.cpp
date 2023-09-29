/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:47:33 by ekoljone          #+#    #+#             */
/*   Updated: 2023/09/28 15:22:20 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *horde = zombieHorde(10, "Markoboy");
	horde[0].announce();
	horde[1].announce();
	horde[3].announce();
	delete [] horde;
	return (0);
}
