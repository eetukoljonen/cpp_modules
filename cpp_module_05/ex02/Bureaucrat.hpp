/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:55:25 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/15 17:51:09 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
public:
	Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &other);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat &other);
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const _NOEXCEPT
		{
			return ("Grade Too High!");
		}
	};
    class GradeTooLowException : public std::exception
	{
		virtual const char *what() const _NOEXCEPT
		{
			return ("Grade Too Low!");
		}
	};
	void				incrementGrade();
	void				decrementGrade();
	void				signForm(AForm &form);
	void				executeForm(AForm const &form);
	std::string const	&getName() const;
	int	const			&getGrade() const;
private:
	std::string const	_name;
	int					_grade;
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &rhs);
#endif
