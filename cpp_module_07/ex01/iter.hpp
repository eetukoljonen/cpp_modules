/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:09:18 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/28 17:33:06 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITER_HPP__
#define __ITER_HPP__

#include <iostream>

template <typename T>
void printArray(T *arr, T len)
{
	for (int i = 0; i < len; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

template <typename T>
void addOne(T *el)
{
	*el +=1;
}

template <typename T1, typename T2, typename T3, typename T4>
void	iter(T1 *addr, T2 len, T3 (*f)(T4 *))
{
	for (int i = 0; i < len; i++)
	{
		f(addr++);
	}
}

#endif