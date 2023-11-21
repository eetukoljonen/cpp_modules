/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:49:14 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/17 16:17:33 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat signer("signer", 1); // can sign anything because highest grade possible
	Bureaucrat executor("executor", 1); // can execute anything because highest grade possible
	Bureaucrat loser("loser", 150); // loser has the lowest possible grade so can't really do anything
	ShrubberyCreationForm shrubbery("test");
	RobotomyRequestForm robotomy("test");
	PresidentialPardonForm presidential("test");
	
	//--------------------------------------------------------------------//

	std::cout << "EXECUTE__NOT__SIGNED______________________________________" << std::endl << std::endl;
	
	executor.executeForm(shrubbery);
	executor.executeForm(robotomy);
	executor.executeForm(presidential);

	std::cout << "__________________________________________________________" << std::endl << std::endl;;

	//--------------------------------------------------------------------//

	std::cout << "SIGN__WITH__TOO__LOW__GRADE_______________________________" << std::endl << std::endl;
	
	loser.signForm(shrubbery);
	loser.signForm(robotomy);
	loser.signForm(presidential);
	
	std::cout << "__________________________________________________________" << std::endl << std::endl;;
	
	//--------------------------------------------------------------------//

	std::cout << "SIGN__FORMS_______________________________________________" << std::endl << std::endl;
	
	std::cout << "FORMS BEFORE SIGNING:" << std::endl;
	std::cout << shrubbery << std::endl
		<< robotomy << std::endl
		<< presidential << std::endl << std::endl;
	signer.signForm(shrubbery);
	signer.signForm(robotomy);
	signer.signForm(presidential);
	std::cout << std::endl << "FORMS AFTER SIGNING:" << std::endl;
	std::cout << shrubbery << std::endl
		<< robotomy << std::endl
		<< presidential << std::endl;
		
	std::cout << "__________________________________________________________" << std::endl << std::endl;;

	//--------------------------------------------------------------------//

	std::cout << "EXECUTE__WITH__TOO__LOW__GRADE____________________________" << std::endl << std::endl;
	
	loser.executeForm(shrubbery);
	loser.executeForm(robotomy);
	loser.executeForm(presidential);

	std::cout << "__________________________________________________________" << std::endl << std::endl;;

	//--------------------------------------------------------------------//

	std::cout << "EXECUTE__SUCCESSFULLY_____________________________________" << std::endl << std::endl;
	
	executor.executeForm(shrubbery);
	executor.executeForm(presidential);
	executor.executeForm(robotomy);

	std::cout << "__________________________________________________________" << std::endl << std::endl;;
	return (0);
}