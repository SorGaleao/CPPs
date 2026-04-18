/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalerConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:14:32 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/02/10 17:21:51 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALORCONVERTER_HPP
#define SCALORCONVERTER_HPP

#include <string>
#include <iostream>
#include <cctype>
#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <sstream>

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter &other);

	static bool isChar(const std::string &str, double &value);
	static bool isInt(const std::string &str, double &value);
	static bool isDouble(const std::string &str, double &value);
	static bool isFloat(const std::string &str, double &value);
	static void print(double value, std::size_t precision = 1);
	static void print_imp(const std::string &num);

public:
	static void convert(const std::string &str);
};

#endif