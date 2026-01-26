/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:07:28 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/16 18:43:01 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
{
Fixed a;
Fixed b(a);
Fixed c;
c = b;
std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;
}

std::cout << std::endl << "=== Testing setRawBits and deep copy ===" << std::endl; {
Fixed a;
Fixed b(a);
Fixed c;
a.setRawBits(42);
c = a;
a.setRawBits(6);
std::cout << a.getRawBits() <<  " = a" << std::endl;
std::cout << b.getRawBits() << " = b" << std::endl;
std::cout << c.getRawBits() << " = c" << std::endl;
}
return 0;

}