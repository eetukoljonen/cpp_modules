/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:00:52 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/24 17:56:45 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	brain = new Brain();
}

Dog::Dog(Dog &cpy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = cpy.type;
	this->brain = new Brain(*cpy.brain);
}

Dog &Dog::operator=(Dog &rhs)
{
	std::cout << "Dog copy assigment operator called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
		delete brain;
		this->brain = new Brain(*rhs.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void	Dog::makeSound(void) const
{
	std::cout << "* WUF WUF *" << std::endl;
}

Brain *Dog::getBrain(void)
{
	return (brain);
}