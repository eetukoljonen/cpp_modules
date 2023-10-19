/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:11:09 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/19 15:26:39 by ekoljone         ###   ########.fr       */
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

MateriaSource &MateriaSource::operator=(MateriaSource &lhs)
{
	if (this != &lhs)
	{
		for (int i = 0; i < max_slots; i++)
			slots[i] = lhs.slots[i]->clone();
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	int i = -1;
	while (++i < max_slots && slots[i]){}
	if (i < max_slots)
	{
		if (!slots[i])
			slots[i] = m;
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