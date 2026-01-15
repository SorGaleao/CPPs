/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:11:57 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/12 17:13:32 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <cmath>

Fixed::Fixed() : fixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int fixedPoint) {
	std::cout << "Int constructor called" << std::endl;
	this->fixedPoint = fixedPoint << FBits;
}

Fixed::Fixed(const float fixedPoint) {
	std::cout << "Float constructor called" << std::endl;
	this->fixedPoint = fixedPoint * (1 << FBits);
}

Fixed::Fixed(const Fixed& other) : fixedPoint(other.fixedPoint) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		fixedPoint = other.getRawBits();
	return (*this);
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl;}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPoint);
}
void Fixed::setRawBits(int const raw){
	fixedPoint = raw;
}

float Fixed::toFloat() const {
	return ((float)fixedPoint / (1 << FBits));
}

int Fixed::toInt() const {
	return (fixedPoint >> FBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}