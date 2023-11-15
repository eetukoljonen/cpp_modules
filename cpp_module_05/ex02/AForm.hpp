/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:27:31 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/15 18:04:15 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AForm_HPP__
#define __AForm_HPP__
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
public:
    AForm(std::string name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &other);
    virtual ~AForm() = 0;
    AForm &operator=(AForm const &other);
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
	class FormNotSigned : public std::exception
	{
		virtual const char *what() const _NOEXCEPT
		{
			return ("Form Not Signed!");
		}
	};
	void				beSigned(Bureaucrat &signer);
	virtual void		execute(Bureaucrat &executor) const = 0;
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

std::ostream &operator<<(std::ostream &stream, AForm const &rhs);

#endif
