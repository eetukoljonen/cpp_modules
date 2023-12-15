/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:41:47 by ekoljone          #+#    #+#             */
/*   Updated: 2023/12/13 12:38:52 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _max_size(0){}

Span::Span(unsigned int size) : _max_size(size){}

Span::Span(Span const &cpy) : _vector(cpy._vector), _max_size(cpy._max_size){}

Span::~Span(){}

Span &Span::operator=(Span const &rhs)
{
    if (this != &rhs)
	{
		this->_vector = rhs._vector;
		this->_max_size = rhs._max_size;
    }
    return (*this);
}
void Span::addNumber(int const &n)
{
	if (_vector.size() + 1 > _max_size)
		throw std::exception();
	_vector.push_back(n);
}

int Span::shortestSpan()
{
	if (_vector.size() <= 1)
		throw std::exception();
	unsigned int smallest = *std::max_element(_vector.begin(), _vector.end());
	std::vector<int> tmp(_vector);
	std::sort(tmp.begin(), tmp.end());
	unsigned int tmp_size = tmp.size();
	for (unsigned int i = 0; i < tmp_size - 1; i++)
	{
		unsigned int span = std::abs(tmp[i] - tmp[i + 1]);
		if (span < smallest)
			smallest = span;
	}
	return (smallest);
}

int Span::longestSpan()
{
	if (_vector.size() <= 1)
		throw std::exception();
	return (*std::max_element(_vector.begin(), _vector.end())
		- *std::min_element(_vector.begin(), _vector.end()));
	return (0);
}

