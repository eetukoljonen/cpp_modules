/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:09:00 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/12 15:11:11 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string animal_type) : type(animal_type)
{
	std::cout << "WrongAnimal param constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &cpy)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	if (this != &cpy)
		this->type = cpy.type;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &lhs)
{
	std::cout << "WrongAnimal copy assigment operator called" << std::endl;
	this->type = lhs.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "* WRONG ANIMAL NOISES *" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}
