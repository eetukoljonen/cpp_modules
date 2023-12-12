/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:08:12 by ekoljone          #+#    #+#             */
/*   Updated: 2023/12/12 19:10:45 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	MutantStack(const MutantStack &cpy);
	~MutantStack();
	MutantStack &operator=(const MutantStack &rhs);
    typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

	iterator			begin();
	const_iterator		cbegin() const;
	iterator			end();
	const_iterator		cend() const;
	reverse_iterator	rbegin();
	reverse_iterator	rend();
};

#include "MutantStack.tpp"

#endif
