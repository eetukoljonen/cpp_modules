/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:03:31 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/26 10:59:00 by ekoljone         ###   ########.fr       */
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
	Cat &operator=(Cat &rhs);
	~Cat();
	void	makeSound(void) const;
private:
	Brain *brain;
};

#endif