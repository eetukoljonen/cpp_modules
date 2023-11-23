/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:04:09 by ekoljone          #+#    #+#             */
/*   Updated: 2023/11/23 10:59:09 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <iostream>
#include <limits>

class ScalarConverter
{
public:
    static void	convert(std::string str);
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &cpy);
    ~ScalarConverter();
    ScalarConverter &operator=(const ScalarConverter &rhs);
};

#endif
