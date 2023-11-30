/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:41:40 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/30 11:16:56 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WHATEVER_HPP__
#define __WHATEVER_HPP__

template <typename T>
T const &max(T const &x, T const &y)
{
	return (x > y ? x : y);
}

template <typename T>
T const &min(T const &x, T const &y)
{
	return (x < y ? x : y);
}

template <typename T>
void swap(T &x, T &y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

#endif
