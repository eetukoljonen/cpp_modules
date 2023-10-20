/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:26:02 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/20 13:40:00 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

Floor::Floor() : m(NULL), next(NULL){}

Floor::Floor(AMateria *m) : m(m), next(NULL){}

Floor::Floor(Floor &cpy) : m(cpy.m), next(cpy.next){}

Floor::~Floor()
{
	if (m)
		delete m;
	if (next)
		delete next;
}
