/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 21:59:27 by jleray            #+#    #+#             */
/*   Updated: 2026/05/24 21:59:27 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0) 
{ std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const int i) : _fixedPoint(0) 
{ 
	std::cout << "Int constructor called" << std::endl; 
	this->setRawBits(i << this->_fBits);
}

Fixed::Fixed(const float f) : _fixedPoint(0)
{ 
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(f * (1 << this->_fBits)));
}


Fixed::Fixed(const Fixed& other) 
{
	*this = other;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedPoint = other._fixedPoint;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& other)
{
	os << other.toFloat();
	return (os);
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits function called" << std::endl;
	return (this->_fixedPoint);
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits function called" << std::endl;
	this->_fixedPoint = raw;
	return ;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fixedPoint / (1 << this->_fBits));
}

int	Fixed::toInt(void) const
{
	return (this->_fixedPoint >> this->_fBits);
}
