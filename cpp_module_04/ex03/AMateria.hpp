/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:28:21 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/18 14:43:13 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AMATERIA_HPP__
#define __AMATERIA_HPP__
#include <iostream>

class AMateria
{
public:
	AMateria();
	AMateria(AMateria &cpy);
	AMateria &operator=(AMateria &lhs);
	~AMateria();
	std::string const	&getType() const;
	virtual AMateria	*clone() const = 0;
	virtual void		use(ICharacter &target);
protected:
	std::string			type;
	std::string			name;
};

#endif