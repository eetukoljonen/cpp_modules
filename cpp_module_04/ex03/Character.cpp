/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:12:46 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/24 17:51:24 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Default"), items(NULL)
{
	for (int i = 0; i < max_slots; i++)
		slots[i] = NULL;
}

Character::Character(std::string name) : _name(name), items(NULL)
{
	for (int i = 0; i < max_slots; i++)
		slots[i] = NULL;
}

Character::Character(Character &cpy) : _name(cpy._name), items(NULL)
{
	for (int i = 0; i < max_slots; i++)
	{
		if (slots[i])
			delete slots[i];
	}
	for (int i = 0; i < max_slots; i++)
		slots[i] = cpy.slots[i]->clone();
}

Character::~Character()
{
	for (int i = 0; i < max_slots; i++)
	{
		if (slots[i])
		{
			delete slots[i];
			slots[i] = NULL;
		}
	}
	if (items)
		delete items;
}

Character &Character::operator=(Character &rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
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

void	Character::equip(AMateria *m)
{
	int i = -1;
	while (++i < max_slots && slots[i]){}
	if (i < max_slots)
	{
		if (!slots[i])
			slots[i] = m;
	}
	else
	{
		if (!items)
		{
			items = new Floor(m);
			return ;
		}
		Floor *tmp = items;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new Floor(m);
	}
}

void	Character::unequip(int idx)
{
	Floor *tmp = items;
	if (idx >= 0 && idx < max_slots)
	{
		if (slots[idx])
		{
			if (!items)
			{
				items = new Floor(slots[idx]);
				slots[idx] = NULL;
				return ;
			}
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new Floor(slots[idx]);
			slots[idx] = NULL;
		}
	}
}

std::string const &Character::getName() const
{
	return (_name);
}

void	Character::use(int idx, ICharacter	&t)
{
	if (idx >= 0 && idx < max_slots && slots[idx])
		slots[idx]->use(t);
}
