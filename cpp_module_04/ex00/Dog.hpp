/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:59:38 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/12 15:02:57 by ekoljone         ###   ########.fr       */
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
	Dog &operator=(Dog &lhs);
	virtual ~Dog();
	virtual void	makeSound(void) const;
};

#endif