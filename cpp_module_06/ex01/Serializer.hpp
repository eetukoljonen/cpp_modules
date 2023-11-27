/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:48:18 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/27 16:34:04 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include "Data.hpp"
#include <iostream>

class Serializer
{
public:
	static uintptr_t	serialize(Data *ptr);
	static Data			*deserialize(uintptr_t raw);
private:
	Serializer();
	Serializer(const Serializer &cpy);
	~Serializer();
	Serializer &operator=(const Serializer &rhs);
};

#endif
