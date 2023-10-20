/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:04:36 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/20 12:32:41 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	brain = new Brain();
}

Cat::Cat(Cat &cpy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	if (this != &cpy)
	{
		this->type = cpy.type;
		this->brain = new Brain(*cpy.brain);
	}
}

Cat &Cat::operator=(Cat &rhs)
{
	std::cout << "Cat copy assigment operator called" << std::endl;
	this->type = rhs.type;
	delete brain;
	this->brain = new Brain(*rhs.brain);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void	Cat::makeSound(void) const
{
	std::cout << "* PURRRRR *" << std::endl;
}
