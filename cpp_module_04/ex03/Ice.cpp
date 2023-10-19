/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:51:46 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/19 14:58:23 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	type = "ice";
}

Ice::Ice(Ice &cpy)
{
	type = cpy.type;
}

Ice::~Ice(){}

Ice &Ice::operator=(Ice &lhs)
{
	if (this != &lhs)
		type = lhs.type;
	return (*this);
}

AMateria *Ice::clone() const
{
	AMateria *new_ice = new Ice();
	return (new_ice);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at "
		<< target.getName() << " *" << std::endl;
}
