/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:42:12 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/30 12:21:04 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include <iostream>

template <typename T>
class Array
{
public:
    Array();
	Array(unsigned int size);
    Array(const Array &cpy);
    ~Array();
    Array		&operator=(const Array &rhs);
	unsigned int const	&size() const;
	T			&operator[](unsigned int index);
private:
	T				*_array;
	unsigned int	_size;
};

#include "Array.tpp"

#endif
