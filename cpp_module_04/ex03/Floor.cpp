/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:26:02 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/26 10:56:00 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

Floor::Floor() : m(NULL), next(NULL){}

Floor::Floor(AMateria *m) : m(m), next(NULL){}

Floor::Floor(Floor &cpy)
{
	m = cpy.m ? cpy.m->clone() : NULL;
    next = cpy.next ? new Floor(*cpy.next) : NULL;
}

Floor &Floor::operator=(Floor &rhs)
{
	if (this != &rhs)
	{
		if (m)
			delete m;
		if (next)
      		delete next;
		m = rhs.m ? rhs.m->clone() : NULL;
        next = rhs.next ? new Floor(*rhs.next) : NULL;
	}
	return (*this);
}

Floor::~Floor()
{
	if (m)
		delete m;
	if (next)
		delete next;
}

Floor *Floor::getNext()
{
	return (next);
}

void Floor::setNext(Floor *next)
{
	this->next = next;
}

AMateria *Floor::getMateria()
{
	return (m);
}

void Floor::setMateria(AMateria *m)
{
	this->m = m;
}
