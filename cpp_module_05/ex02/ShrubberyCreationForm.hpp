/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:40:20 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/15 17:40:34 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
    void	execute(Bureaucrat &executor) const;
private:
    std::string _target;
};

#endif
