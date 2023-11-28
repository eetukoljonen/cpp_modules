/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:42:12 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/28 18:16:34 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include <iostream>

template <typename T>
class Array
{
public:
    Array< T >() : _array(new T), _size(1){}
	Array< T >(unsigned int size) : _array(new T[size]), _size(size){}
    Array< T >(const Array< T > &cpy) : _size(cpy._size)
	{
		_array = new T[cpy._size];
		for (int i = 0; i < cpy._size; i++)
			_array[i] = cpy._array[i];
	}
    ~Array< T >(){delete [] _array;}
    Array< T > &operator=(const Array< T > &rhs)
	{
		if (this != &rhs)
		{
			_array = new T[rhs._size];
			for (int i = 0; i < rhs._size; i++)
				_array[i] = rhs._array[i];
			_size = rhs._size;
		}
		return (*this);
	}
	int const	&size() const {return (_size);}
	T			&operator[](int index)
	{
		if (index < 0 || index > _size)
			throw (std::exception());
		return (_array[index]);
	}
private:
	T		*_array;
	int		_size;
};

#endif
