/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:49:14 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/15 14:36:17 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	//-------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------

	std::cout << "TOO__LOW__GRADE__REQUIRED__TO__SIGN__INTANSIATION_________" << std::endl << std::endl;
	try
	{
		Form form("Paper", 151, 1);
	}
	catch(std::exception &e)
	{
		std::cout << "execption caught with the message: " << e.what() << std::endl;
	}
	std::cout << "__________________________________________________________" << std::endl << std::endl;;

	//-------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------

	std::cout << "TOO__HIGH__GRADE__REQUIRED__TO__SIGN__INTANSIATION________" << std::endl << std::endl;
	try
	{
		Form form1("Paper1", 0 , 1);
	}
	catch(std::exception &e)
	{
		std::cout << "execption caught with the message: " << e.what() << std::endl;
	}
	std::cout << "__________________________________________________________" << std::endl << std::endl;;

	//-------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------

	std::cout << "TOO__LOW__GRADE__REQUIRED__TO__EXECUTE__INTANSIATION______" << std::endl << std::endl;
	try
	{
		Form form2("Paper2", 1 , 151);
	}
	catch(std::exception &e)
	{
		std::cout << "execption caught with the message: " << e.what() << std::endl;
	}
	std::cout << "__________________________________________________________" << std::endl << std::endl;;

	//-------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------

	std::cout << "TOO__HIGH__GRADE__REQUIRED__TO__EXECUTE__INTANSIATION_____" << std::endl << std::endl;
	try
	{
		Form form3("Paper3", 1 , 0);
	}
	catch(std::exception &e)
	{
		std::cout << "execption caught with the message: " << e.what() << std::endl;
	}
	std::cout << "__________________________________________________________" << std::endl << std::endl;;


	//-------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------

	std::cout << "BUREAUCRAT__WITH__TOO__LOW__GRADE__TO__SIGN_______________" << std::endl << std::endl;
	Bureaucrat	eetu("eetu", 2);
	Form		paper("paper", 1, 1);
	std::cout << eetu << std::endl;
	std::cout << paper << std::endl;
	try
	{
		eetu.signForm(paper);
	}
	catch(std::exception &e)
	{
		std::cout << "execption caught with the message: " << e.what() << std::endl;
	}
	std::cout << "paper after the signing attempt: " << paper << std::endl;
	std::cout << "__________________________________________________________" << std::endl << std::endl;;

	//-------------------------------------------------------------------------------------
	//-------------------------------------------------------------------------------------

	std::cout << "BUREAUCRAT__SIGNS__FORM__SUCCESFULLY______________________" << std::endl << std::endl;
	Bureaucrat	eetu1("eetu1", 1);
	Form		paper1("paper1", 1, 1);
	std::cout << eetu1 << std::endl;
	std::cout << paper1 << std::endl;
	try
	{
		eetu1.signForm(paper1);
	}
	catch(std::exception &e)
	{
		std::cout << "execption caught with the message: " << e.what() << std::endl;
	}
	std::cout << "paper1 after signing: " << paper1 << std::endl;
	std::cout << "__________________________________________________________" << std::endl << std::endl;;
	return (0);
}