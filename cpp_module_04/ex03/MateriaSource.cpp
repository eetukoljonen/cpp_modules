/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:11:09 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/26 10:55:52 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < max_slots; i++)
		slots[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource &cpy)
{
	for (int i = 0; i < max_slots; i++)
		slots[i] = cpy.slots[i]->clone();
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < max_slots; i++)
	{
		if (slots[i])
			delete slots[i];
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < max_slots; i++)
		{
			if (slots[i])
				delete slots[i];
		}
		for (int i = 0; i < max_slots; i++)
			slots[i] = rhs.slots[i]->clone();
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < max_slots; i++)
	{
		if (!slots[i] && m)
		{
			slots[i] = m;
			return ;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < max_slots && slots[i]; i++)
	{
		if (!type.compare(slots[i]->getType()))
			return (slots[i]->clone());
	}
	return (0);
}