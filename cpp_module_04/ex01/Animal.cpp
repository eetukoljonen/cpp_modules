/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:55:21 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/24 17:54:00 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string animal_type) : type(animal_type)
{
	std::cout << "Animal param constructor called" << std::endl;
}

Animal::Animal(Animal &cpy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->type = cpy.type;
}

Animal &Animal::operator=(Animal &rhs)
{
	std::cout << "Animal copy assigment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "* ANIMAL NOISES *" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}
