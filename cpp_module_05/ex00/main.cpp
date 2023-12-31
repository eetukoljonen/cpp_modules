/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:49:14 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/21 10:38:27 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	//-------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------
	
	std::cout << "INCREMENT__TESTS__________________________________________" << std::endl << std::endl;
	Bureaucrat eetu("Eetu", 2);
	std::cout << "before incrementing: ";
	std::cout << eetu << std::endl;
	eetu.incrementGrade();
	std::cout << "after incrementing: ";
	std::cout << eetu << std::endl;
	std::cout << "using try and catch block to increment one more" << std::endl;
	try
	{
		eetu.incrementGrade();
	}
	catch(Bureaucrat::GradeTooHighException)
	{
		std::cout << "GradeTooHighExecption caught" << std::endl;
	}
	std::cout << "__________________________________________________________" << std::endl;
	std::cout << std::endl;

	//-------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------

	std::cout << "DECREMENT__TESTS__________________________________________" << std::endl << std::endl;
	Bureaucrat eetu2("Eetu2", 149);
	std::cout << "before decrementing: ";
	std::cout << eetu2 << std::endl;
	eetu2.decrementGrade();
	std::cout << "after decrementing: ";
	std::cout << eetu2 << std::endl;
	std::cout << "using try and catch block to decrement one more" << std::endl;
	try
	{
		eetu2.decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException)
	{
		std::cout << "GradeTooLowExecption caught" << std::endl;
	}
	std::cout << "__________________________________________________________" << std::endl;
	std::cout << std::endl;

	//-------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------

	std::cout << "TOO__LOW__INTANSIATION____________________________________" << std::endl << std::endl;
	try
	{
		Bureaucrat eetu3("Eetu3", 151);
	}
	catch(Bureaucrat::GradeTooLowException)
	{
		std::cout << "GradeTooLowExecption caught" << std::endl;
	}
	std::cout << "__________________________________________________________" << std::endl;
	std::cout << std::endl;

	//-------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------

	std::cout << "TOO__HIGH_INTANSIATION____________________________________" << std::endl << std::endl;
	try
	{
		Bureaucrat eetu4("Eetu4", 0);
	}
	catch(Bureaucrat::GradeTooHighException)
	{
		std::cout << "GradeTooHighExecption caught" << std::endl;
	}
	std::cout << "__________________________________________________________" << std::endl;
	return (0);
}