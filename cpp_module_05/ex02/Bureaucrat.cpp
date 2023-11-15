/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:55:29 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/15 18:10:50 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &cpy) : _name(cpy._name), _grade(cpy._grade){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    if (this != &rhs)
	{
		_grade = rhs._grade;
    }
    return (*this);
}

void	Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	_grade -= 1;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	_grade += 1;
}

std::string const	&Bureaucrat::getName() const
{
	return (_name);
}

int const	&Bureaucrat::getGrade() const
{
	return (_grade);
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &rhs)
{
	std::cout << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (stream);
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException)
	{
		std::cout << _name << " couldn't sign form "
			<< form.getName() << " beacuse grade is too low" << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException)
	{
		std::cout << _name << " couldn't execute form "
			<< form.getName() << " beacuse grade is too low" << std::endl;
	}
	catch (AForm::FormNotSigned)
	{
		std::cout << _name << " couldn't execute form "
			<< form.getName() << " beacuse form is not signed" << std::endl;
	}
}
