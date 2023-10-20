/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:27:48 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/20 16:55:08 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

//even though materiasource has only 4 slots of materia we can learn more of them without causing memoryleaks

void	materiasource_test()
{
	std::cout << "MateriaSource test" << std::endl;
	std::cout << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	// trying to learn over 4 materias
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	AMateria* tmp;
	tmp = src->createMateria("ice");
	std::cout << tmp->getType() << std::endl;
	delete tmp;
	tmp = src->createMateria("cure");
	std::cout << tmp->getType() << std::endl;
	delete tmp;
	tmp = src->createMateria("mulli");
	if (tmp)
		std::cout << tmp->getType() << std::endl;
	delete src;
	std::cout << "___________________________" << std::endl;
	std::cout << std::endl;
}

void	character_usage_test()
{
	std::cout << "Character usage test" << std::endl;
	std::cout << std::endl;
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	AMateria *tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	//going over the 4 slot maximum
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->use(1, *bob);
	me->use(2, *bob);
	// trying unexisting index slot
	me->use(100, *bob);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);
	me->unequip(4);
	me->unequip(5);
	delete me;
	delete bob;
	delete src;
	std::cout << "___________________________" << std::endl;
	std::cout << std::endl;
}

//subjects test file

void	test_42()
{
	std::cout << "42 test" << std::endl;
	std::cout << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

int main(int argc, char **argv)
{
	std::string const str = "42";
	if (argc > 1)
	{
		// start program like this ./test 42
		if (!str.compare(argv[1]))
			test_42();
		return (0);
	}
	materiasource_test();
	character_usage_test();
	return (0);
}
