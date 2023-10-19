/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:02:52 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/19 16:49:00 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "Floor.hpp"

class Character : public ICharacter
{
public:
	Character();
	Character(std::string name);
	Character(Character &cpy);
	virtual ~Character();
	Character &operator=(Character &lhs);
	virtual std::string const	&getName() const;
	virtual void				equip(AMateria *m);
	virtual void				unequip(int idx);
	virtual void				use(int idx, ICharacter& t);
private:
	std::string					_name;
	AMateria					*slots[4];
	Floor						*items;
	static int const			max_slots = 4;
};

#endif