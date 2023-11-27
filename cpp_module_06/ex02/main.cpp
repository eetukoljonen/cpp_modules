/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:51:44 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/27 18:21:39 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base	*generate(void)
{
	switch (rand() % 3)
	{
	case 0:
		return (new A());
	case 1:
		return (new B());
	case 2:
		return (new C());
	default:
		break;
	}
	return (NULL);
}

void	indentify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "type = A pointer" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "type = B pointer" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "type = C pointer" << std::endl;
}

void	indentify(Base &p)
{
	try
	{
		A a = dynamic_cast<A &>(p);
		std::cout << "type = A reference" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
	try
	{
		B b = dynamic_cast<B &>(p);
		std::cout << "type = B reference" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
	try
	{
		C c = dynamic_cast<C &>(p);
		std::cout << "type = C reference" << std::endl;
		return ;
	}
	catch(const std::exception& e){}
}

int main()
{
	srand(time(0));
	Base *rand = generate();
	if (rand)
	{
		indentify(rand);
		indentify(*rand);
		delete rand;
	}
	return (0);
}