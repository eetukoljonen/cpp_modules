/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:40:30 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/10 12:06:59 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(int const a);
	Fixed(float const a);
	Fixed(Fixed const &src);
	~Fixed(void);
	Fixed	&operator=(Fixed const &rhs);
	float	toFloat(void) const;
	int		toInt(void) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
private:
	int					value;
	static int const	f_bits = 8;
};

std::ostream &operator<<(std::ostream &stream, const Fixed &rhs);