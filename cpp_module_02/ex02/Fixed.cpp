/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:40:46 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/10 14:07:51 by ekoljone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int const a) : value(a << f_bits)
{
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(float const a) : value(std::roundf(a * (1 << f_bits)))
{
	std::cout << "Float constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed & Fixed::operator=( Fixed const &rhs )
{
	if (this != &rhs)
		this->value = rhs.value;
	return (*this);
}

std::ostream &operator<<(std::ostream &stream, Fixed const &rhs)
{
	return (stream << rhs.toFloat());
}

int Fixed::getRawBits(void) const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->value) / (1 << f_bits));
}

int Fixed::toInt(void) const
{
	return (std::roundf(toFloat()));
}

bool Fixed::operator>(Fixed const &rhs) const
{
	return (this->value > rhs.value);
}

bool Fixed::operator<(Fixed const &rhs) const
{
	return (this->value < rhs.value);
}

bool Fixed::operator<=(Fixed const &rhs) const
{
	return (this->value <= rhs.value);
}

bool Fixed::operator>=(Fixed const &rhs) const
{
	return (this->value >= rhs.value);
}

bool Fixed::operator!=(Fixed const &rhs) const
{
	return (this->value != rhs.value);
}

bool Fixed::operator==(Fixed const &rhs) const
{
	return (this->value == rhs.value);
}

Fixed Fixed::operator+(Fixed const &rhs)
{
	return (Fixed(toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(Fixed const &rhs)
{
	return (Fixed(toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(Fixed const &rhs)
{
	return (Fixed(toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(Fixed const &rhs)
{
	return (Fixed(toFloat() / rhs.toFloat()));
}

Fixed &Fixed::operator++(void)
{
	++this->value;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->value++;
	return (temp);
}

Fixed &Fixed::operator--(void)
{
	--this->value;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->value--;
	return (temp);
}

Fixed &Fixed::min(Fixed &lhs, Fixed &rhs)
{
	return (lhs < rhs ? lhs : rhs);
}

Fixed const &Fixed::min(Fixed const &lhs, Fixed const &rhs)
{
	return (lhs < rhs ? lhs : rhs);
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs)
{
	return (lhs > rhs ? lhs : rhs);
}

Fixed const &Fixed::max(Fixed const &lhs, Fixed const &rhs)
{
	return (lhs > rhs ? lhs : rhs);
}
