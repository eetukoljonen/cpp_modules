/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:59:38 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/26 10:56:50 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP__
#define __DOG_HPP__
#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(Dog &cpy);
	Dog &operator=(Dog &rhs);
	~Dog();
	void	makeSound(void) const;
};

#endif