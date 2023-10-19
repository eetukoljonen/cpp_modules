/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:00:06 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/19 14:58:09 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	type = "cure";
}

Cure::Cure(Cure &cpy)
{
	type = cpy.type;
}

Cure::~Cure(){}

Cure &Cure::operator=(Cure &lhs)
{
	if (this != &lhs)
		type = lhs.type;
	return (*this);
}

AMateria *Cure::clone() const
{
	AMateria *new_Cure = new Cure();
	return (new_Cure);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals "
		<< target.getName() << "'s wounds *" << std::endl;
}