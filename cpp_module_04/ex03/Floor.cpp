/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:26:02 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/24 13:22:43 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

Floor::Floor() : m(NULL), next(NULL){}

Floor::Floor(AMateria *m) : m(m), next(NULL){}

Floor::Floor(Floor &cpy) : m(cpy.m->clone()), next(new Floor(cpy.next->m->clone())){}

Floor::~Floor()
{
	if (m)
		delete m;
	if (next)
		delete next;
}
