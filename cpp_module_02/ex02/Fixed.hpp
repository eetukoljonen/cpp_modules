/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:40:30 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/10 12:07:22 by ekoljone         ###   ########.fr       */
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
	Fixed	&operator=( Fixed const &rhs );
	bool	operator>(Fixed const &rhs) const;
	bool	operator<(Fixed const &rhs) const;
	bool	operator<=(Fixed const &rhs) const;
	bool	operator>=(Fixed const &rhs) const;
	bool	operator!=(Fixed const &rhs) const;
	bool	operator==(Fixed const &rhs) const;
	Fixed	operator+(Fixed const &rhs);
	Fixed	operator-(Fixed const &rhs);
	Fixed	operator*(Fixed const &rhs);
	Fixed	operator/(Fixed const &rhs);
	Fixed	&operator++(void);
	Fixed	operator++(int);
	Fixed	&operator--(void);
	Fixed	operator--(int);
	float	toFloat(void) const;
	int		toInt(void) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	static Fixed		&min(Fixed &lhs, Fixed &rhs);
	static Fixed const	&min(Fixed const &lhs, Fixed const &rhs);
	static Fixed		&max(Fixed &lhs, Fixed &rhs);
	static Fixed const	&max(Fixed const &lhs, Fixed const &rhs);
private:
	int					value;
	static int const	f_bits = 8;
};

std::ostream & operator<<(std::ostream &stream, const Fixed &rhs);