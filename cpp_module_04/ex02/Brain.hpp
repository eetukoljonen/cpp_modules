/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:07:54 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/20 12:34:01 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__
#include <iostream>

class Brain
{
public:
	Brain();
	Brain(Brain &cpy);
	Brain &operator=(Brain &rhs);
	~Brain();
	void				setIdea(int index, std::string const &idea);
	std::string const	&getIdea(int index) const;
private:
	std::string ideas[100];
};

#endif