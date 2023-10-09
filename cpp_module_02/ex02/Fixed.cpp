/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoljone <ekoljone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:40:46 by ekoljone          #+#    #+#             */
/*   Updated: 2023/10/09 17:48:04 by ekoljone         ###   ########.fr       */
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
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &rhs)
		this->value = rhs.value;
	return *this;
}

std::ostream &operator<<(std::ostream &stream, Fixed const &rhs)
{
	return (stream << rhs.toFloat());
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
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
	std::cout << "Greater than operator called" << std::endl;
	return (this->value > rhs.value);
}

bool Fixed::operator<(Fixed const &rhs) const
{
	std::cout << "Less than operator called" << std::endl;
	return (this->value < rhs.value);
}

bool Fixed::operator<=(Fixed const &rhs) const
{
	std::cout << "Less or equals to operator called" << std::endl;
	return (this->value <= rhs.value);
}

bool Fixed::operator>=(Fixed const &rhs) const
{
	std::cout << "Greater or equals to operator called" << std::endl;
	return (this->value <= rhs.value);
}

bool Fixed::operator!=(Fixed const &rhs) const
{
	std::cout << "Not equals to operator called" << std::endl;
	return (this->value != rhs.value);
}

bool Fixed::operator==(Fixed const &rhs) const
{
	std::cout << "Is equals to operator called" << std::endl;
	return (this->value == rhs.value);
}

Fixed Fixed::operator+(Fixed const &rhs)
{
	std::cout << "Sum operator called" << std::endl;
	return (Fixed(toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(Fixed const &rhs)
{
	std::cout << "Subtract operator called" << std::endl;
	return (Fixed(toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(Fixed const &rhs)
{
	std::cout << "Subtract operator called" << std::endl;
	return (Fixed(toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(Fixed const &rhs)
{
	std::cout << "Subtract operator called" << std::endl;
	return (Fixed(toFloat() / rhs.toFloat()));
}

Fixed &Fixed::operator++(void)
{
	std::cout << "Pre-increment operator called" << std::endl;
	++this->value;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	std::cout << "Post-increment operator called" << std::endl;
	Fixed temp(*this);
	this->value++;
	return (temp);
}

Fixed &Fixed::operator--(void)
{
	std::cout << "Pre-decrement operator called" << std::endl;
	--this->value;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	std::cout << "Post-decrement operator called" << std::endl;
	Fixed temp(*this);
	this->value--;
	return (temp);
}

Fixed &Fixed::min(Fixed &lhs, Fixed &rhs)
{
	std::cout << "min member function called" << std::endl;
	return (lhs < rhs ? lhs : rhs);
}

Fixed const &Fixed::min(Fixed const &lhs, Fixed const &rhs)
{
	std::cout << "min member function called" << std::endl;
	return (lhs < rhs ? lhs : rhs);
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs)
{
	std::cout << "min member function called" << std::endl;
	return (lhs > rhs ? lhs : rhs);
}

Fixed const &Fixed::max(Fixed const &lhs, Fixed const &rhs)
{
	std::cout << "min member function called" << std::endl;
	return (lhs > rhs ? lhs : rhs);
}