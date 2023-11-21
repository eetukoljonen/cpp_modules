/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:40:25 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/21 14:15:11 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _target("Default"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	(void)rhs;
    return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw(ShrubberyCreationForm::FormNotSigned());
	if (executor.getGrade() > getGradeRequiredToExecute())
		throw (ShrubberyCreationForm::GradeTooLowException());
	std::ofstream new_file(_target + "_shrubbery");
	if (!new_file.is_open())
	{
		std::cerr << "Error opening the file!" << std::endl;
		return ;
	}
	new_file <<
		"          .     .  .      +     .      .          .\n"
        "     .       .      .     #       .           .\n"
        "        .      .         ###            .      .      .\n"
        "      .      .   \"#:. .:##\"##:. .:#\"  .      .\n"
        "          .      . \"####\"###\"####\"  .\n"
        "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n"
        "  .             \"#########\"#########\"        .        .\n"
        "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n"
        "     .     .  \"#######\"##\"####\"##\"#######\"                  .\n"
        "                .\"##\"#####\"#####\"##\"           .      .\n"
        "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n"
        "      .     \"#######\"##\"####\"##\"#######\"      .     .\n"
        "    .    .     \"#####\"\"#######\"\"####\"    .      .\n"
        "            .     \"      000      \"    .     .\n"
        "       .         .   .   000     .        .       .\n"
        ".. .. ..................O000O........................ ......\n";
	new_file.close();
}