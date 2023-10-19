/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:58:02 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/19 13:29:54 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CURE_HPP__
#define __CURE_HPP__
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(Cure &cpy);
	Cure &operator=(Cure &lhs);
	virtual ~Cure();
	virtual AMateria	*clone() const;
	virtual void		use(ICharacter &target);
};

#endif