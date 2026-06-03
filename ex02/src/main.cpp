/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleray <marvin@d42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:12:35 by jleray            #+#    #+#             */
/*   Updated: 2026/06/03 14:12:35 by jleray           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));
	Fixed c(Fixed(100) / b);

	std::cout << "a : ";
	std::cout << a << std::endl;
	std::cout << "a++ : ";
	std::cout << a++ << std::endl;
	std::cout << "a : ";
	std::cout << a << std::endl;
	std::cout << "++a : ";
	std::cout << ++a << std::endl;
	std::cout << "b : ";
	std::cout << b << std::endl;
	std::cout << "a / b : ";
	std::cout << a / b << std::endl;
	std::cout << "a / 0 : ";
	std::cout << a / 0 << std::endl;
	std::cout << "c++ : ";
	std::cout << c++ << std::endl;
	std::cout << "c : ";
	std::cout << c << std::endl;

	std::cout << "max : ";
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << "min : ";
	std::cout << Fixed::min(a, b) << std::endl;
}
