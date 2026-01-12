/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:10:18 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/12 18:11:43 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>

class Fixed {
private:
	int fixedPoint;
	static const int FBits = 8;
	
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed &other);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt(void) const;
	float toFloat() const;

	// Comparisons
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	// Arithmetic
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	// Increment/Decrement
	Fixed& operator++();    // ++a
	Fixed operator++(int);  // a++
	Fixed& operator--();
	Fixed operator--(int);

	// Min/Max
	static Fixed& min(Fixed& a, Fixed& b) { return (a < b) ? a : b; }
	static const Fixed& min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b; }
	static Fixed& max(Fixed& a, Fixed& b) { return (a > b) ? a : b; }
	static const Fixed& max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b; }
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif