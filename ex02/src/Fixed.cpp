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

#include "../include/Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0) {}

Fixed::Fixed(const int i) : _fixedPoint(0) 
{ 
	this->setRawBits(i << this->_fBits);
}

Fixed::Fixed(const float f) : _fixedPoint(0)
{ 
	this->setRawBits(roundf(f * (1 << this->_fBits)));
}


Fixed::Fixed(const Fixed& other) 
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_fixedPoint = other._fixedPoint;
	return (*this);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->getRawBits() != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed& other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++this->_fixedPoint;
	return (temp);
}

Fixed& Fixed::operator++(void)
{
	this->_fixedPoint++;
	return (*this);
}

Fixed Fixed::operator-(const Fixed& other) const
{	
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--this->_fixedPoint;
	return (temp);
}

Fixed& Fixed::operator--(void)
{
	this->_fixedPoint--;
	return (*this);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const
{	
	if (other.getRawBits() == 0)
	{
		std::cout << "Error : div by ";
		return (0);
	}
	return (Fixed(this->toFloat() * other.toFloat()));
}

std::ostream& operator<<(std::ostream& os, const Fixed& other)
{
	os << other.toFloat();
	return (os);
}

const Fixed&	Fixed::min(const Fixed& first, const Fixed& scd)
{
	if (first.toFloat() < scd.toFloat())
		return (first);
	else
		return (scd);
}

const Fixed&	Fixed::max(const Fixed& first, const Fixed& scd)
{
	if (first.toFloat() < scd.toFloat())
		return (scd);
	else
		return (first);
}

Fixed&	Fixed::min(Fixed& first, Fixed& scd)
{
	if (first.toFloat() < scd.toFloat())
		return (first);
	else
		return (scd);
}

Fixed&	Fixed::max(Fixed& first, Fixed& scd)
{
	if (first.toFloat() < scd.toFloat())
		return (scd);
	else
		return (first);
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const
{
	return (this->_fixedPoint);
}

void Fixed::setRawBits(const int raw)
{
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
