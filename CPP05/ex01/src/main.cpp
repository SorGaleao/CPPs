/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:48:31 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/04/28 10:49:12 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main() {
	std::cout << std::endl << "=== Test 1: Form creation and info ===" << std::endl;
	try {
		Form f1("TaxForm", 100, 50);
		std::cout << f1 << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 2: Form signing success ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 50);
		std::cout << bob << std::endl;
		Form f2("Permit", 100, 50);
		std::cout << f2 << std::endl;
		bob.signForm(f2); // Should succeed
		std::cout << f2 << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test 3: Form signing failure ===" << std::endl;
	try {
		Bureaucrat intern("Intern", 150);
		std::cout << intern << std::endl;
		Form secret("TopSecret", 1, 1);
		std::cout << "Before: \n" << secret << std::endl;
		intern.signForm(secret); // Should fail
		std::cout << "After: \n" << secret << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

		std::cout << std::endl << "=== Test 4: Form signing even if execute is lower ===" << std::endl;
	try {
		Bureaucrat analyst("Analyst", 50);
		std::cout << analyst << std::endl;
		Form papers("Papers", 50, 20);
		std::cout << "Before: \n" << papers << std::endl;
		analyst.signForm(papers); // Should work
		std::cout << "After: \n" << papers << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	return 0;
}