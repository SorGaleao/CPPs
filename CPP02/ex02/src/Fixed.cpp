/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:11:57 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/12 18:41:04 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <cmath>

Fixed::Fixed() : fixedPoint(0) {}

Fixed::Fixed(const int fixedPoint) {
	this->fixedPoint = fixedPoint << FBits;
}

Fixed::Fixed(const float fixedPoint) {
	this->fixedPoint = fixedPoint * (1 << FBits);
}

Fixed::Fixed(const Fixed& other) : fixedPoint(other.fixedPoint) {}

Fixed& Fixed::operator=(const Fixed &other) {
	if (this != &other)
		fixedPoint = other.getRawBits();
	return (*this);
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const {
	return (this->fixedPoint);
}

void Fixed::setRawBits(int const raw){
	fixedPoint = raw;
}

float Fixed::toFloat() const {
	return ((float)fixedPoint / (1 << FBits));
}

int Fixed::toInt() const {
	return fixedPoint >> FBits;
}

// Comparisons
bool Fixed::operator>(const Fixed& other) const { return (this->fixedPoint > other.fixedPoint);}
bool Fixed::operator<(const Fixed& other) const { return (this->fixedPoint < other.fixedPoint);}
bool Fixed::operator>=(const Fixed& other) const { return (this->fixedPoint >= other.fixedPoint);}
bool Fixed::operator<=(const Fixed& other) const { return (this->fixedPoint <= other.fixedPoint);}
bool Fixed::operator==(const Fixed& other) const { return (this->fixedPoint == other.fixedPoint);}
bool Fixed::operator!=(const Fixed& other) const { return (this->fixedPoint != other.fixedPoint);}

// Arithmetic
Fixed Fixed::operator+(const Fixed& other) const { 
	Fixed result;
	result.fixedPoint = this->fixedPoint + other.fixedPoint;
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const { Fixed result;
	result.fixedPoint = this->fixedPoint - other.fixedPoint;
	return (result);
}

Fixed Fixed::operator*(const Fixed& other) const { 
	Fixed result;
	result.fixedPoint = this->fixedPoint * other.fixedPoint >> FBits;
	return (result);
}

Fixed Fixed::operator/(const Fixed& other) const { Fixed result;
	result.fixedPoint = this->fixedPoint * other.fixedPoint >> FBits;
	return (result);
}

// Increment/Decrement
Fixed& Fixed::operator++() {
	this->fixedPoint++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->fixedPoint++;
	return temp;
}

Fixed& Fixed::operator--() {
	this->fixedPoint--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->fixedPoint--;
	return temp;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}