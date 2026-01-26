/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:07:28 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/16 19:16:56 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

int main(void) {
	
{ Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
}

std::cout << "\n=== Testing arithmetic operators ===" << std::endl; {
	Fixed x(10);
	Fixed y(3);
	std::cout << "x = 10" << std::endl;
	std::cout << "y = 3" << std::endl;
	std::cout << "\nx + y = " << x + y << std::endl;
	std::cout << "x - y = " << x - y << std::endl;
	std::cout << "x * y = " << x * y << std::endl;
	std::cout << "x / y = " << x / y << std::endl;
} {
	std::cout << "\n=== Testing comparison operator ===" << std::endl;
	Fixed a1(5);
	Fixed a2(5);
	Fixed a3(10);
	std::cout << "a1 = 5" << std::endl;
	std::cout << "a2 = 5" << std::endl;
	std::cout << "a3 = 10" << std::endl;
	std::cout << "\na1 == a2 = " << (a1 == a2) << std::endl;
	std::cout << "a1 != a3 = " <<(a1 != a3) << std::endl;
	std::cout << "a1 < a3 = " << (a1 < a3) << std::endl;
	std::cout << "a3 > a2 = " <<(a3 > a2) << std::endl;
	std::cout << "a1 <= a2 = " << (a1 <= a2) << std::endl;
	std::cout << "a3 >= a1 = " << (a3 >= a1) << std::endl;
} {
	std::cout << "\n=== Testing comparison operator ===" << std::endl;
	Fixed a1(5);
	Fixed a2(5);
	Fixed a3(10);
	std::cout << "a1 = 5" << std::endl;
	std::cout << "a2 = 5" << std::endl;
	std::cout << "a3 = 10" << std::endl;
	std::cout << "\na1 == a2 = " << (a1 == a2) << std::endl;
	std::cout << "a1 != a3 = " <<(a1 != a3) << std::endl;
	std::cout << "a1 < a3 = " << (a1 < a3) << std::endl;
	std::cout << "a3 > a2 = " <<(a3 > a2) << std::endl;
	std::cout << "a1 <= a2 = " << (a1 <= a2) << std::endl;
	std::cout << "a3 >= a1 = " << (a3 >= a1) << std::endl;
} {
	std::cout << "\n=== Testing min/max ===" << std::endl;
	Fixed b1(1);
	Fixed b2(2);
	std::cout << "b1 = 1" << std::endl;
	std::cout << "b2 = 2" << std::endl;
	std::cout << "\nmin " << Fixed::min(b1, b2) << std::endl;
	std::cout << "max " << Fixed::max(b1, b2) << std::endl;
}
	return 0;
}