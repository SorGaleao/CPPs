/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:34:30 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/05/12 17:20:51 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : stack(other.stack) {}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other)
		stack = other.stack;
	return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(char c) {
	if (c != '+' && c != '-' && c != '*' && c != '/')
		return false;
	return true;
}
bool RPN::isValid(const std::string& arg) {
	for (size_t i = 0; i < arg.size(); ++i) {
		char c = arg[i];
		if (!isOperator(c) && !std::isdigit(static_cast<unsigned char>(c)) && c != ' ') {
			std::cerr << "Invalid input, character not accepted." << std::endl;
			return false;
		}
	}
	return true;
}

bool RPN::handleOperator(std::stack<int>& stack, char op, int& res) {
	int b = stack.top(); stack.pop();
	int a = stack.top(); stack.pop();
	switch (op) {
		case '+': res = a + b; break;
		case '-': res = a - b; break;
		case '*': res = a * b; break;
		case '/': 
			if (b == 0) {
				std::cerr << "Error: divide by zero" << std::endl;
				return false;
			} else if (a == 0) {
				res = 0;
				return true;
			}
			res = a / b; break;
		default: return false;
	}
	return true;
}

bool RPN::rpn(std::string arg) {
	if (!isValid(arg))
		return false;
		
	size_t pos1 = 0;
	std::string check;
	int result = 0;
	arg.push_back(' '); // add space in back to handle the last op
	for (size_t i = 0; i < arg.size(); ++i) {
		if (arg[i] != ' ') continue;
		size_t pos2 = i;
		check = arg.substr(pos1, pos2 - pos1);
		if (check.empty()) { pos1 = pos2 + 1; continue; }
		if (check.size() > 1) {
			std::cerr << "Invalid input, missing space btween characters or number bigger than 10." << std::endl;
			return false;
		}
		char token = check[0];
		if (std::isdigit(static_cast<unsigned char>(token))) {
			stack.push(static_cast<int>(token - '0'));
		}
		else if (isOperator(token)) {
			if (stack.size() < 2) {
				std::cerr << "Not enough numbers in stack to progress with the expression" << std::endl;
				return false;
			}
			if (!handleOperator(stack, token, result)) return false;
			stack.push(result);
		} else {
			std::cerr << "Invalid token: " << check << std::endl;
			return false;
		}
		pos1 = pos2 + 1;
	}
	if (stack.size() != 1) {
		std::cerr << "Error: invalid expression, stack contains " << stack.size() << " elements" << std::endl;
		return false;
	}

	std::cout << stack.top() << std::endl;
	return true;
}


