/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:27:31 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/21 14:10:36 by ekoljone         ###   ########.fr       */
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
	AForm();
    AForm(std::string name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &cpy);
    virtual ~AForm() = 0;
    AForm &operator=(AForm const &rhs);
    class GradeTooHighException : public std::exception{};
    class GradeTooLowException : public std::exception{};
	class FormNotSigned : public std::exception{};
	void				beSigned(Bureaucrat &signer);
	virtual void		execute(Bureaucrat const &executor) const = 0;
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
