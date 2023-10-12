/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:03:31 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/12 16:22:07 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
#define __CAT_HPP__
#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(Cat &cpy);
	Cat &operator=(Cat &lhs);
	virtual ~Cat();
	virtual void	makeSound(void) const;
private:
	Brain *brain;
};

#endif