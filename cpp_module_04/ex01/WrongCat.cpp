/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:13:10 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/24 17:57:36 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat &cpy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->type = cpy.type;
}

WrongCat &WrongCat::operator=(WrongCat &rhs)
{
	std::cout << "WrongCat copy assigment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "* WRONG PURRRRR *" << std::endl;
}
