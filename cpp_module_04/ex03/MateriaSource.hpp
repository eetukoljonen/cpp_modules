/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:07:32 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/26 10:56:02 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATERIASOURCE_HPP__
#define __MATERIASOURCE_HPP__
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(MateriaSource &cpy);
	~MateriaSource();
	MateriaSource		&operator=(MateriaSource &rhs);
	void				learnMateria(AMateria *m);
	AMateria			*createMateria(std::string const &type);
private:
	AMateria			*slots[4];
	static int const	max_slots = 4;
};

#endif