/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:49:14 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/15 18:10:51 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	AForm *form = new ShrubberyCreationForm("home");
	Bureaucrat eetu("eetu", 1);
	eetu.executeForm(*form);
	std::cout << *form << std::endl;
	return (0);
}