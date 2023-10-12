/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:07:49 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/12 15:17:10 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGANIMAL_HPP__
#define __WRONGANIMAL_HPP__
#include <iostream>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(std::string animal_type);
	WrongAnimal(WrongAnimal &cpy);
	WrongAnimal &operator=(WrongAnimal &lhs);
	virtual ~WrongAnimal();
	void		makeSound(void) const;
	std::string	getType(void) const;
protected:
	std::string type;
};

#endif