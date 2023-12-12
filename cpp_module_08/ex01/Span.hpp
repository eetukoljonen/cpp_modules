/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:43:32 by ekoljone          #+#    #+#             */
/*   Updated: 2023/12/12 14:29:35 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <vector>
#include <iostream>

class Span
{
public:
    Span();
	Span(unsigned int size);
    Span(const Span &cpy);
    ~Span();
    Span	&operator=(const Span &rhs);
    void	addNumber(int const &n);
	int		shortestSpan();
	int		longestSpan();
	
	template <typename T>
	void	addRange(typename T::iterator begin, typename T::iterator end);
private:
	std::vector<int>	_vector;
	unsigned int		_max_size;
};

template <typename T>
void	Span::addRange(typename T::iterator begin, typename T::iterator end)
{
	if (_max_size < _vector.size() + std::distance(begin, end))
		throw(std::exception());
	_vector.insert(_vector.end(), begin, end);
}

#endif
