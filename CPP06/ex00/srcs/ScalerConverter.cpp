/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalerConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:14:35 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/04/29 09:26:38 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalerConverter.hpp"

#include <cmath>
#include <limits>
#include <iomanip>

// Helper: check printable
static bool is_printable(int c) {
    return std::isprint(static_cast<unsigned char>(c));
}

bool ScalarConverter::isChar(const std::string &str, double &value) {
    if (str.size() == 1 && !std::isdigit(static_cast<unsigned char>(str[0]))) {
        char c = str[0];
        value = static_cast<double>(static_cast<unsigned char>(c));
        return true;
    }
    if (str.size() == 3 && str[0] == '\'' && str[2] == '\'') {
        char c = str[1];
        value = static_cast<double>(static_cast<unsigned char>(c));
        return true;
    }
    return false;
}

bool ScalarConverter::isInt(const std::string &str, double &value) {
    if (str.empty())
        return false;
    std::size_t pos = 0;
    if (str[pos] == '+' || str[pos] == '-') {
        ++pos;
        if (pos >= str.size())
            return false;
    }
    for (std::size_t i = pos; i < str.size(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return false;
    }
    errno = 0;
    char *endptr = NULL;
    long long v = std::strtoll(str.c_str(), &endptr, 10);
    if (errno == ERANGE)
        return false;
    if (endptr == NULL || *endptr != '\0')
        return false;
    value = static_cast<double>(v);
    return true;
}

bool ScalarConverter::isDouble(const std::string &str, double &value) {
    std::size_t dot = str.find('.');
    if (dot == std::string::npos)
        return false;
    std::string before = str.substr(0, dot);
    std::string after = str.substr(dot + 1);
    if (after.empty())
        return false;
    for (std::size_t i = 0; i < after.size(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(after[i])))
            return false;
    }
    // parse integer part without changing global state: use strtoll on `before`
    long long intpart = 0;
    if (before.empty())
        intpart = 0;
    else {
        errno = 0;
        char *endptr = NULL;
        intpart = std::strtoll(before.c_str(), &endptr, 10);
        if (errno == ERANGE) return false;
        if (endptr == NULL || *endptr != '\0') return false;
    }
    std::string frac = std::string("0.") + after;
    errno = 0;
    char *endptr2 = NULL;
    double f = std::strtod(frac.c_str(), &endptr2);
    if (errno == ERANGE || endptr2 == NULL || *endptr2 != '\0')
        return false;
    // apply sign from before (if it starts with '-')
    if (!before.empty() && before[0] == '-')
        value = static_cast<double>(intpart) - f;
    else
        value = static_cast<double>(intpart) + f;
    return true;
}

bool ScalarConverter::isFloat(const std::string &str, double &value) {
    if (str.size() < 2 || str[str.size() - 1] != 'f') {
        return false;
    }
    std::string core = str.substr(0, str.size() - 1);
    return isDouble(core, value);
}

void ScalarConverter::print_imp(const std::string &num) {
    std::cout << "char: impossible"<< std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << num << "f" << std::endl;
    std::cout << "double: " << num << std::endl;
}

void ScalarConverter::print(double num, std::size_t precision) {
    // char
    if (std::isnan(num) || std::isinf(num)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    } else {
        long long vi = static_cast<long long>(num);
        if (vi < std::numeric_limits<int>::min() || vi > std::numeric_limits<int>::max()) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
        } else {
            int i = static_cast<int>(vi);
            if (i < 0 || i > 127) {
                std::cout << "char: impossible" << std::endl;
            } else if (!is_printable(i)) {
                std::cout << "char: Non displayable" << std::endl;
            } else {
                std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
            }
            std::cout << "int: " << i << std::endl;
        }
    }
    // float and double formatting
    std::cout << std::fixed << std::setprecision(static_cast<int>(precision));
    float f = static_cast<float>(num);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(num) << std::endl;
}

void ScalarConverter::convert(const std::string &str) {
    double value = 0.0;
    std::size_t precision = 1;
    // pseudo-literals: nan/nanf, +inf/-inf/+inff/-inff
    if (str == "nan" || str == "nanf") {
        print_imp("nan");
        return;
    }
    if (str == "inf" || str == "+inf" || str == "-inf" ||
        str == "inff" || str == "+inff" || str == "-inff") {
        std::string norm = str;
        if (!norm.empty() && norm[norm.size() - 1] == 'f') norm.erase(norm.size() - 1, 1);
        print_imp(norm);
        return;
    }

    // order: char, int, float, double
    if (isChar(str, value)) {
        precision = 1;
        print(value, precision);
        return;
    }
    if (isInt(str, value)) {
        precision = 1;
        print(value, precision);
        return;
    }
    // float (with trailing f)
    if (isFloat(str, value)) {
        // compute fractional digits from core
        std::string core = str.substr(0, str.size() - 1);
        std::size_t dot = core.find('.');
        if (dot != std::string::npos) {
            std::string after = core.substr(dot + 1);
            precision = after.size() > 0 ? after.size() : 1;
        }
        print(value, precision);
        return;
    }
    // double
    if (isDouble(str, value)) {
        std::size_t dot = str.find('.');
        if (dot != std::string::npos) {
            std::string after = str.substr(dot + 1);
            precision = after.size() > 0 ? after.size() : 1;
        }
        print(value, precision);
        return;
    }

    std::cerr << "Unknown input" << std::endl;
}
