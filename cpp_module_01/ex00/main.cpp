/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:08:20 by ekoljone          #+#    #+#             */
/*   Updated: 2023/09/27 17:17:57 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	randomChump("Kalle");
	randomChump("Marko");
	randomChump("Jouni");
	Zombie *Kalevi = newZombie("Kalevi");
	Kalevi->announce();
	delete Kalevi;
	return (0);
}
