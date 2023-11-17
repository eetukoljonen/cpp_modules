/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:08:11 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/17 13:18:07 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &cpy);
    ~RobotomyRequestForm();
    RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
    void	execute(Bureaucrat const &executor) const;
private:
    std::string _target;
};

#endif // RobotomyRequestForm_HPP
