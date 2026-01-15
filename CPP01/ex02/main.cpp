/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:37:44 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/15 17:46:15 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "The memory address of the string is " << &str << std:: endl;
	std::cout << "The memory address of the stringPTR is " << stringPTR << std:: endl;
	std::cout << "The memory address of the stringREF is " << &stringREF << std:: endl;

	std::cout << "The value of the string " << str << std:: endl;
	std::cout << "The value pointed to by stringPTR " << *stringPTR << std:: endl;
	std::cout << "The value pointed to by stringREF " << stringREF << std:: endl;
}