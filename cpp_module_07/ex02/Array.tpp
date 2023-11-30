/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:29:22 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/30 12:10:52 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0){}

template <typename T>
Array<T>::Array(unsigned int size) : _array(new T[size]), _size(size){}

template <typename T>
Array<T>::Array(Array<T> const &cpy) : _size(cpy._size)
{
	this->_array = NULL;
	if (cpy._size > 0)
	{
		this->_array = new T[cpy._size];
		for (unsigned int i = 0; i < cpy._size; i++)
			this->_array[i] = cpy._array[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	if (_size > 0)
		delete [] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &rhs)
{
	if (this != &rhs)
	{
		if (this->_size > 0)
		{
			delete [] this->_array;
			this->_array = NULL;
		}
		if (rhs._size > 0)
		{
			this->_array = new T[rhs._size];
			for (unsigned int i = 0; i < rhs._size; i++)
				this->_array[i] = rhs._array[i];
		}
		this->_size = rhs._size;
	}
	return (*this);
}

template <typename T>
unsigned int const	&Array<T>::size() const {return (_size);}

template <typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index < 0 || index >= _size)
		throw (std::exception());
	return (_array[index]);
}
