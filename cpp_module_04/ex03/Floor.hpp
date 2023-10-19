/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:17:41 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/19 16:44:22 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FLOOR_HPP__
#define __FLOOR_HPP__
#include "AMateria.hpp"

class Floor
{
public:
	Floor();
	Floor(AMateria *m);
	Floor(Floor &cpy);
	~Floor();
	Floor &operator=(Floor &lhs);
	AMateria	*m;
	Floor		*next;
};

#endif