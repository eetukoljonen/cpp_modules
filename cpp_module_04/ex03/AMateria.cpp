/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:32:11 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/18 14:44:24 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(AMateria &cpy)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	this->type = cpy.type;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria &AMateria::operator=(AMateria &lhs)
{
	std::cout << "AMateria copy assigment operator called" << std::endl;
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
	std::cout << type << " * shoots amateria at " << target.name << " *" << std::endl;
}
