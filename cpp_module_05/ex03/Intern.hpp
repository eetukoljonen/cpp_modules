/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:33:38 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/17 16:53:18 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_HPP__
#define __INTERN_HPP__
#include <iostream>
#include "AForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern &cpy);
    ~Intern();
    Intern &operator=(const Intern &rhs);
    AForm	*makeForm(std::string form, std::string target);
private:
	AForm	*makeShrubbery(std::string target);
	AForm	*makeRobotomy(std::string target);
	AForm	*makePresidential(std::string target);
};

typedef AForm *(Intern::*funcPtr)(std::string target);

#endif
