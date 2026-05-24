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

Fixed::Fixed() : _fixedPoint(0) {}

Fixed::Fixed(const Fixed& other) { *this = other ; }

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_fixedPoint = other._fixedPoint;
	return (*this);
}

Fixed::~Fixed() {}
