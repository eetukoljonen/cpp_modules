/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:11:54 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/20 16:58:09 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void	testDeepCopy(void)
{
	//test for the deep copy
	Dog test;
	for (int i = 0; i < 4; i++)
		test.getBrain()->setIdea(i, "MORO");
	Dog cpy(test);
	std::cout << std::endl;
	std::cout << "address of test: " << &test << std::endl;
	std::cout << "address of cpy: " << &cpy << std::endl;
	std::cout << "address of test brain: " << test.getBrain() << std::endl;
	std::cout << "address of cpy brain: " << cpy.getBrain() << std::endl;
	std::cout << std::endl;
	std::cout << "values pointed by test brain:" << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << test.getBrain()->getIdea(i) << std::endl;
	std::cout << std::endl;
	std::cout << "values pointed by cpy brain:" << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout <<cpy.getBrain()->getIdea(i) << std::endl;
	std::cout << std::endl;
}

int main()
{
	//test for creating array of two diffrent type of animals
	Animal *animals[4];
	
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << std::endl;
	testDeepCopy();
	//freeing memory
	for (int i = 0; i < 4; i++)
		delete animals[i];
	return 0;
}