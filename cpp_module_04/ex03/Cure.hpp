/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:58:02 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/26 10:56:07 by ekoljone         ###   ########.fr       */
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
	Cure &operator=(Cure &rhs);
	~Cure();
	AMateria	*clone() const;
	void		use(ICharacter &target);
};

#endif