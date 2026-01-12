/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:10:18 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/12 16:23:40 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CPP
# define FIXED_CPP

#include <string>
#include <iostream>

class Fixed {
private:
	int fixedPoint;
	static const int FBits = 8;
	
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed &other);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif