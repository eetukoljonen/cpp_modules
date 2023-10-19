/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:32:11 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/19 15:03:33 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("Default"){}

AMateria::AMateria(AMateria &cpy) : type(cpy.type) {}

AMateria::~AMateria(){}

AMateria &AMateria::operator=(AMateria &lhs)
{
	if (this != &lhs)
	{
		this->type = lhs.type;
	}
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << type << " * shoots amateria at " << target.getName() << " *" << std::endl;
}
