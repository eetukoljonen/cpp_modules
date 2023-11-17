/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:36:05 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/17 13:36:10 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIALPARDONFORM_HPP__
#define __PRESIDENTIALPARDONFORM_HPP__
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &cpy);
    ~PresidentialPardonForm();
    PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
    void	execute(Bureaucrat const &executor) const;
private:
    std::string _target;
};

#endif
