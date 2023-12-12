/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:11:03 by ekoljone          #+#    #+#             */
/*   Updated: 2023/12/11 17:31:41 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

#include <iostream>
#include <algorithm>

template<typename T>
int &easyfind(T &c, int const &find)
{
	typename T::iterator it = std::find(c.begin(), c.end(), find);
	if (it == c.end())
		throw (std::exception());
	return (*it);
}

#endif