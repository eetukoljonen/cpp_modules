/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:41:40 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/28 16:07:19 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TEMPLATES_HPP__
#define __TEMPLATES_HPP__

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
