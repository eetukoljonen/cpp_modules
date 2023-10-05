/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:40:30 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/04 15:45:26 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(Fixed const &src);
	~Fixed(void);
	Fixed & operator = ( Fixed const &rhs );
	int getRawBits(void) const;
	void setRawBits(int const raw);
private:
	int value;
	static int const f_bits = 8;
};