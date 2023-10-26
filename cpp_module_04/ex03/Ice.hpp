/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:45:49 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/26 10:56:05 by ekoljone         ###   ########.fr       */
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
	Ice &operator=(Ice &rhs);
	~Ice();
	AMateria	*clone() const;
	void		use(ICharacter &target);
};

#endif