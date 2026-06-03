/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 20:21:51 by jleray            #+#    #+#             */
/*   Updated: 2026/05/24 20:21:51 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_fixedPoint;
		static const int	_fBits = 8;
	 public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed& other);
		~Fixed();
		Fixed&					operator=(const Fixed& other);
		bool					operator>(const Fixed& other) const;
		bool					operator>=(const Fixed& other) const;
		bool					operator<(const Fixed& other) const;
		bool					operator<=(const Fixed& other) const;
		bool					operator==(const Fixed& other) const;
		bool					operator!=(const Fixed& other) const;
		Fixed					operator+(const Fixed& other) const;
		Fixed					operator++(int);
		Fixed&					operator++(void);
		Fixed					operator-(const Fixed& other) const;
		Fixed					operator--(int);
		Fixed&					operator--(void);
		Fixed					operator*(const Fixed& other) const;
		Fixed					operator/(const Fixed& other) const;
		friend std::ostream& 	operator<<(std::ostream& os, const Fixed& other);
		static Fixed&				min(Fixed& first, Fixed& scd);
		static Fixed&				max(Fixed& first, Fixed& scd);
		const static Fixed&			min(const Fixed& first, const Fixed& scd);
		const static Fixed&			max(const Fixed& first, const Fixed& scd);
		int						getRawBits(void) const;
		void					setRawBits(int const raw);
		float 					toFloat(void) const;
		int						toInt(void) const;

};

#endif
