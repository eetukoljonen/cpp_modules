/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:43:16 by ekoljone          #+#    #+#             */
/*   Updated: 2023/12/13 12:54:18 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main_42()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << std::endl;

//------------------------------------------------------------//
//------------comparing with a list---------------------------//
//------------------------------------------------------------//

	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << mlist.back() << std::endl;
    mlist.pop_back();
	std::cout << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	//[...]
	mlist.push_back(0);
	std::list<int>::iterator it1 = mlist.begin();
	std::list<int>::iterator ite1 = mlist.end();
	++it1;
	--it1;
	while (it1 != ite1)
	{
		std::cout << *it1 << std::endl;
		++it1;
	}
	std::list<int> s1(mlist);
	return (0);
}

int main(int argc, char **argv)
{
//------------------------------------------------------------//
//------------subjects main func == ./test 42-----------------//
//------------------------------------------------------------//

	if (argc == 2 && !std::string("42").compare(argv[1]))
		return (main_42());

//------------------------------------------------------------//
//------------normal iterators--------------------------------//
//------------------------------------------------------------//

	MutantStack<int> mstack;
	for (int i = 0; i < 5; i++)
		mstack.push(i);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << std::endl;

//------------------------------------------------------------//
//------------reverse iterators-------------------------------//
//------------------------------------------------------------//

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		rit++;
	}
	std::cout << std::endl;

//------------------------------------------------------------//
//------------copy tests--------------------------------------//
//------------------------------------------------------------//

	MutantStack<int> cpy(mstack);
	MutantStack<int>::iterator it1 = cpy.begin();
	MutantStack<int>::iterator ite1 = cpy.end();
	while (it1 != ite1)
	{
		std::cout << *it1 << std::endl;
		it1++;
	}
	std::cout << std::endl;
	MutantStack<int> cpy1;
	cpy1 = cpy;
	MutantStack<int>::iterator it2 = cpy1.begin();
	MutantStack<int>::iterator ite2 = cpy1.end();
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		it2++;
	}
	return (0);
}
