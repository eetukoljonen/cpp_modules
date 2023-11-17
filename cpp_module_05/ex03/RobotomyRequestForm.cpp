/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:08:09 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/17 14:25:45 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cpy)
 : AForm("RobotomyRequestForm", 72, 45), _target(cpy._target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
    if (this != &rhs)
	{
		_target = rhs._target;
    }
    return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw(RobotomyRequestForm::FormNotSigned());
	if (executor.getGrade() > getGradeRequiredToExecute())
		throw (RobotomyRequestForm::GradeTooLowException());
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << " robotomy failed" << std::endl;
}