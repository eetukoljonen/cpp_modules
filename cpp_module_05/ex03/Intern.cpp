/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:33:40 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/21 10:51:15 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(){}

Intern::Intern(Intern const &cpy){(void)cpy;}

Intern::~Intern(){}

Intern &Intern::operator=(Intern const &rhs)
{
    (void)rhs;
    return (*this);
}

AForm *Intern::makeShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	int					ctr = 0;
	funcPtr				ptr[3] = {&Intern::makeRobotomy, &Intern::makePresidential,
									&Intern::makeShrubbery};
	std::string const	forms[3] = {"robotomy request", "presidential pardon",
										"shrubbery creation"};
	while (ctr < 3 && form.compare(forms[ctr]))
		ctr++;
	if (ctr < 3)
		return (this->*ptr[ctr])(target);
	std::cout << form << " form doesn't exist" << std::endl;
	return (NULL);
}
