/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:55:25 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/21 14:07:35 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &other);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat &other);
	class GradeTooHighException : public std::exception{};
    class GradeTooLowException : public std::exception{};
	void				incrementGrade();
	void				decrementGrade();
	void				signForm(Form &form);
	std::string const	&getName() const;
	int	const			&getGrade() const;
private:
	std::string const	_name;
	int					_grade;
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &rhs);
#endif
