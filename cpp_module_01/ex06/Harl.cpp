/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:00:07 by ekoljone          #+#    #+#             */
/*   Updated: 2023/09/29 16:30:05 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::complain(std::string level)
{
	int		ctr = 0;
	funcPtr	ptr[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	funcName[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (level.compare(funcName[ctr]) && ctr < 4)
		ctr++;
	switch (ctr)
	{
	case 0:
		(this->*ptr[ctr++])();
		std::cout << std::endl;
	case 1:
		(this->*ptr[ctr++])();
		std::cout << std::endl;
	case 2:
		(this->*ptr[ctr++])();
		std::cout << std::endl;
	case 3:
		(this->*ptr[ctr])();
		break;
	case 4:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

void	Harl::debug(void) const
{
	std::cout << "[ DEBUG ]" << std::endl
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void) const
{
	std::cout << "[ INFO ]" << std::endl
		<< "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void) const
{
	std::cout << "[ WARNING ]" << std::endl
		<< "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}
void	Harl::error(void) const
{
	std::cout << "[ ERROR ]" << std::endl
		<< "This is unacceptable! I want to speak to the manager now." << std::endl;
}
