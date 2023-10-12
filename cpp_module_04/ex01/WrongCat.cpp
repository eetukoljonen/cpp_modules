/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:13:10 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/12 15:15:14 by ekoljone         ###   ########.fr       */
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
	if (this != &cpy)
		this->type = cpy.type;
}

WrongCat &WrongCat::operator=(WrongCat &lhs)
{
	std::cout << "WrongCat copy assigment operator called" << std::endl;
	this->type = lhs.type;
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
