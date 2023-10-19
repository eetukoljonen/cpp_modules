/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:45:49 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/19 13:30:11 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICE_HPP__
#define __ICE_HPP__
#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(Ice &cpy);
	Ice &operator=(Ice &lhs);
	virtual ~Ice();
	virtual AMateria	*clone() const;
	virtual void		use(ICharacter &target);
};

#endif