/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:49:14 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/22 12:43:25 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	AForm *newForm = NULL;
	Intern someRandomIntern;
	newForm = someRandomIntern.makeForm("robotomy request", "Bender");
	if (newForm)
	{
		std::cout << *newForm << std::endl;
		delete newForm;
	}
	newForm = someRandomIntern.makeForm("presidential pardon", "Fender");
	if (newForm)
	{
		std::cout << *newForm << std::endl;
		delete newForm;
	}
	newForm = someRandomIntern.makeForm("shrubbery creation", "Tender");
	if (newForm)
	{
		std::cout << *newForm << std::endl;
		delete newForm;
	}
	newForm = someRandomIntern.makeForm("AAAAAAAAAA", "BAAAAAA");
	if (newForm)
	{
		std::cout << *newForm << std::endl;
		delete newForm;
	}
	return (0);
}