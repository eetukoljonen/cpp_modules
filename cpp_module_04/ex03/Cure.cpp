/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:00:06 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/24 13:23:16 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){}

Cure::Cure(Cure &cpy) : AMateria(cpy.type){}

Cure::~Cure(){}

Cure &Cure::operator=(Cure &rhs)
{
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

AMateria *Cure::clone() const
{
	return (new Cure());
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals "
		<< target.getName() << "'s wounds *" << std::endl;
}