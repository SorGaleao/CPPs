/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:07:28 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/16 18:46:08 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

int main(void) {

{Fixed a;
Fixed const b(10);
Fixed const c(42.42f);
Fixed const d(b);
a = Fixed(1234.4321f);
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}


std::cout << "\n=== Scaling ===" << std::endl; {
Fixed x(1);
Fixed y(1.5f);
std::cout << "x(1) raw bits: " << x.getRawBits() << std::endl;
std::cout << "y(1.5f) raw bits: " << y.getRawBits() << std::endl;
}

std::cout << "\n=== Precision ===" << std::endl; {
Fixed p(0.1f);
Fixed q(0.2f);
std::cout << "p(0.1f) is " << p << std::endl;
std::cout << "q(0.2f) is " << q << std::endl;
}

std::cout << "\n=== Float vs Fixed ===" << std::endl; {
float f = 0.1f;
Fixed fx(0.1f);
std::cout << "float 0.1 = " << f << std::endl;
std::cout << "fixed 0.1 = " << fx << std::endl;
}

std::cout << "\n=== Testing copy constructor ===" << std::endl; {
Fixed m(5.05f);
Fixed n(m);
m = Fixed(10);
std::cout << "m is " << m << std::endl;
std::cout << "n is " << n << std::endl;
}

std::cout << "\n=== Negative numbers ===" << std::endl; {
Fixed neg(-42.42f);
std::cout << "neg is " << neg << std::endl;
std::cout << "neg as int is " << neg.toInt() << std::endl;
} 

std::cout << "\n=== toInt truncation ===" << std::endl; {
Fixed t(9.99f);
std::cout << "t is " << t << std::endl;
std::cout << "t as int is " << t.toInt() << std::endl;
}
return 0;
}