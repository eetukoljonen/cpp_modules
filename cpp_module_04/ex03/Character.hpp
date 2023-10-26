/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:02:52 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/26 10:56:04 by ekoljone         ###   ########.fr       */
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
	~Character();
	Character &operator=(Character &rhs);
	std::string const	&getName() const;
	void				equip(AMateria *m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& t);
private:
	std::string					_name;
	AMateria					*slots[4];
	Floor						*items;
	static int const			max_slots = 4;
};

#endif