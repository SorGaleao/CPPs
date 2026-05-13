/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:34:38 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/05/12 16:14:54 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
#define RPN_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>

class RPN {
	private:
		std::stack<int> stack;
		bool isOperator(char c);
		bool isValid(const std::string& arg);
		bool handleOperator(std::stack<int>& stack, char op, int& res);
	
	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();
		bool rpn(std::string arg);

};

#endif
