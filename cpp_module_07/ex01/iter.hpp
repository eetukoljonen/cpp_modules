/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:09:18 by ekoljone          #+#    #+#             */
/*   Updated: 2023/12/11 12:33:42 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITER_HPP__
#define __ITER_HPP__

#include <iostream>

template< typename T >
void print_element( T& x )
{
  std::cout << x << std::endl;
  return;
}

template <typename T>
void	iter(T *addr, size_t len, void (*f)(T const &))
{
	for (size_t i = 0; i < len; i++)
	{
		f(addr[i]);
	}
}

template <typename T>
void	iter(T *addr, size_t len, void (*f)(T &))
{
	for (size_t i = 0; i < len; i++)
	{
		f(addr[i]);
	}
}

#endif