/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:12:46 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/19 17:02:05 by ekoljone         ###   ########.fr       */
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
	Floor *tmp = cpy.items;
	for (int i = 0; i < max_slots; i++)
		slots[i] = cpy.slots[i]->clone();
	while (tmp)
	{
		items = new Floor();
		items->m = tmp->m->clone();
		tmp = tmp->next;
	}
}

Character::~Character()
{
	for (int i = 0; i < max_slots; i++)
	{
		if (slots[i])
			delete slots[i];
	}
	if (items)
		delete items;
}

Character &Character::operator=(Character &lhs)
{
	Floor *tmp = lhs.items;
	if (this != &lhs)
	{
		_name = lhs._name;
		for (int i = 0; i < max_slots; i++)
			slots[i] = lhs.slots[i]->clone();
		while (tmp)
		{
			items = new Floor();
			items->m = tmp->m->clone();
			tmp = tmp->next;
		}
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
}

void	Character::unequip(int idx)
{
	Floor *tmp = items;
	if (idx >= 0 && idx < max_slots)
	{
		if (slots[idx])
		{
			while (tmp)
				tmp = tmp->next;
			tmp = new Floor(slots[idx]);
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
