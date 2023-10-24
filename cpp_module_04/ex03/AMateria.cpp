/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:32:11 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/24 13:15:08 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(){}

AMateria::AMateria(std::string const &type) : type(type){}

AMateria::AMateria(AMateria &cpy)
{
	*this = cpy;
}

AMateria::~AMateria(){}

AMateria &AMateria::operator=(AMateria &rhs)
{
	(void)rhs;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}
