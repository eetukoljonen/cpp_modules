/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:27:31 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/15 15:57:26 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
#define __FORM_HPP__
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
    Form(std::string name, int gradeToSign, int gradeToExecute);
    Form(const Form &other);
    ~Form();
    Form& operator=(const Form &other);
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
	void				beSigned(Bureaucrat &signer);
	std::string const	&getName() const;
	int const			&getGradeRequiredToSign() const;
	int const			&getGradeRequiredToExecute() const;
	bool const			&getIsSigned() const;
private:
	std::string const	_name;
	bool				_isSigned;
	int const			_gradeRequiredToSign;
	int const			_gradeRequiredToExecute;
};

std::ostream &operator<<(std::ostream &stream, Form const &rhs);

#endif
