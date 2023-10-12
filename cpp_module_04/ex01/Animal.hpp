/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:53:35 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/12 16:40:01 by ekoljone         ###   ########.fr       */
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
	Animal &operator=(Animal &lhs);
	virtual ~Animal();
	virtual void	makeSound(void) const;
	std::string		getType(void) const;
protected:
	std::string type;
};

#endif