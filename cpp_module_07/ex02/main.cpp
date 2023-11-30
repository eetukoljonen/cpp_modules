/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:57:54 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/30 12:21:05 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#define MAX_VAL 750


//main function provided by the subject
int main_42()
{
	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
	return (0);
}

int main(int argc, char **argv)
{
	// main provided by subject
	if (argc == 2 && !std::string("42").compare(argv[1]))
	{
		return (main_42());
	}
	// int array
	Array<int> intarr(4);
	std::cout << "size of intarr = " << intarr.size() << std::endl;
	for (int i = 0; i < 4; i++)
		intarr[i] = i;
	for (int i = 0; i < 4; i++)
		std::cout << intarr[i] << std::endl;
	std::cout << std::endl;

	// float array
	Array<float> floatarr(3);
	std::cout << "size of floatarr = " << floatarr.size() << std::endl;
	floatarr[0] = 1.2f;
	floatarr[1] = 2.3f;
	floatarr[2] = 3.4f;
	try
	{
		floatarr[3] = 4.5f;
	}
	catch(const std::exception& e)
	{
		std::cout << "out of range" << std::endl;
	}
	for (int i = 0; i < 3; i++)
		std::cout << floatarr[i] << std::endl;
	std::cout << std::endl;
	
	// char array

	Array<char> chararr(3);
	std::cout << "size of chararr = " << chararr.size() << std::endl;
	chararr[0] = 'a';
	chararr[1] = 'b';
	chararr[2] = 'c';
	for (int i = 0; i < 3; i++)
		std::cout << chararr[i] << std::endl;
	std::cout << std::endl;

	// copy tests

	Array<float> cpyfloat(floatarr);
	std::cout << "cpyfloat values" << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << cpyfloat[i] << std::endl;
	cpyfloat[0] = 33.5f;
	cpyfloat[1] = 42.42f;
	cpyfloat[2] = 100.92f;
	std::cout << "cpyfloat new values" << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << cpyfloat[i] << std::endl;
	std::cout << "checking that original floatarr values didn't change" << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << floatarr[i] << std::endl;
	return (0);
}
