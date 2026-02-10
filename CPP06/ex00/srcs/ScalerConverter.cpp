/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalerConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:14:35 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/02/10 17:19:25 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalerConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string &str) {
	if (str.size() == 1 && !std::isdigit(static_cast<unsigned char>(str[0])))
		return true;
	if (str.size() == 3 && str[0] == '\'' && str[2] == '\'') 
		return true;
	return false;
}

bool ScalarConverter::isInt(const std::string &str) {
	std::size_t i = 0;
	if (str[i] == '+' || str[i] == '-')
		++i;
	if (i >= str.size())
		return false;
	for (; i < str.size(); ++i) {
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return false;
	}
	return true;
}

bool ScalarConverter::isDouble(const std::string &str) {
    std::size_t i = 0;
    if (str.empty()) return false;
    if (str[i] == '+' || str[i] == '-') ++i;

    bool has_dot = false;
    bool has_digit_before = false;
    bool has_digit_after = false;

    for (; i < str.size(); ++i) {
        unsigned char c = static_cast<unsigned char>(str[i]);
        if (std::isdigit(c)) {
            if (!has_dot) has_digit_before = true;
            else has_digit_after = true;
        } else if (c == '.' && !has_dot) {
            has_dot = true;
        } else {
            return false;
        }
    }
    return has_dot && has_digit_before && has_digit_after;
}

bool ScalarConverter::isFloat(const std::string &str) {
	if (str.size() < 2 || str[str.size() - 1] != 'f') {
		return false;
	}
	std::string core = str.substr(0, str.size() - 1);
	return isDouble(core);
}

ScalarConverter::type ScalarConverter::detect_type(const std::string &str, double &value, bool &is_pseudo) {
	bool pseudo_float = false;
	if (str.empty())
		return false;
	if (is_pseudo_literal(str, pseudo_float, value)) {
		is_pseudo = true;
		return (pseudo_float) ? ScalarConverter::FLOAT : ScalarConverter::DOUBLE;
	}
	if (isChar(str))
		return ScalarConverter::CHAR;
	if (isInt(str))
		return ScalarConverter::INT;
	if (isFloat(str))
		return ScalarConverter::FLOAT;
	if (isDouble(str))
		return ScalarConverter::DOUBLE;
	return ScalarConverter::DOUBLE;
}

void ScalarConverter::convert(std::string& str) {
	
}