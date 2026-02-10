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

#ifndef SCALORCONVERTER_H
#define SCALORCONVERTER_H

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
	~ScalarConverter();
	
	enum type {
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		UNKWON
	};

	static bool isChar(const std::string &str);
	static bool isInt(const std::string &str);
	static bool isDouble(const std::string &str);
	static bool isFloat(const std::string &str);
	static type detect_type(const std::string &str, double &value, bool &is_pseudo);
	
	public:
		static void convert(std::string& str);
};

#endif