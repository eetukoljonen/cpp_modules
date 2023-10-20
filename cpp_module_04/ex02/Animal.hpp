/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:53:35 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/20 12:34:01 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__
#include <iostream>
#include "Brain.hpp"

class Animal
{
public:
	Animal();
	Animal(std::string animal_type);
	Animal(Animal &cpy);
	Animal &operator=(Animal &rhs);
	virtual ~Animal();
	virtual void	makeSound(void) const = 0;
	std::string		getType(void) const;
protected:
	std::string type;
};

#endif