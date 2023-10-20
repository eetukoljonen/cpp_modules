/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:11:12 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/20 12:32:58 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain &cpy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	if (this != &cpy)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = cpy.ideas[i];
	}
}

Brain &Brain::operator=(Brain &rhs)
{
	std::cout << "Brain copy assigment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = rhs.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::setIdea(int index, std::string const &idea)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

std::string const	&Brain::getIdea(int index) const
{
	return (ideas[index]);
}
