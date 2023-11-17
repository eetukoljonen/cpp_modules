/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:36:08 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/17 14:52:19 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &cpy)
	: AForm("PresidentialPardonForm", 25, 5), _target(cpy._target){}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
    if (this != &rhs)
	{
		_target = rhs._target;
    }
    return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw(PresidentialPardonForm::FormNotSigned());
	if (executor.getGrade() > getGradeRequiredToExecute())
		throw (PresidentialPardonForm::GradeTooLowException());
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}