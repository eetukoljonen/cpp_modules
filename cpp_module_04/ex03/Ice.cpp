/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:51:46 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/20 15:46:06 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){}

Ice::Ice(Ice &cpy) : AMateria(cpy.type){}

Ice::~Ice(){}

Ice &Ice::operator=(Ice &rhs)
{
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

AMateria *Ice::clone() const
{
	return (new Ice());
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at "
		<< target.getName() << " *" << std::endl;
}
