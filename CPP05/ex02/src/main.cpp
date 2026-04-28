/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:48:31 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/04/28 12:08:33 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
std::srand(std::time(0));
    
    std::cout << "\n=== Creation of Bureaucrats ===\n";

    Bureaucrat alice("Alice", 1);
    std::cout << alice << std::endl;
    Bureaucrat bob("Bob", 50);
    std::cout << bob << std::endl;
    Bureaucrat charlie("Charlie", 146);
    std::cout << charlie << std::endl;
	Bureaucrat david("David", 45);
    std::cout << david << std::endl;
    
    std::cout << "\n=== Creation of Forms ===\n";
    ShrubberyCreationForm shrub("home");
    std::cout << shrub << std::endl;
    RobotomyRequestForm robot("Robotomy Request");
    std::cout << robot << std::endl;
    PresidentialPardonForm pardon("Gab");
    std::cout << pardon << std::endl;

    // Shrubbery
    std::cout << "\n=== Test 1: ShrubberyCreationForm - Can't execute, not signed ===\n";
    try {
        alice.executeForm(shrub);
    } 
	catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
	
	std::cout << "\n=== Test 2: ShrubberyCreationForm - Sign and Execute ===\n";
    try {
        alice.signForm(shrub);
        alice.executeForm(shrub);
    } 
	catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // Robotomy
	std::cout << "\n=== Test 3: RobotomyRequestForm - Can't execute, not signed ===\n";
    try {
        bob.executeForm(robot); 
    } 
	catch (std::exception &e) {
    	std::cout << e.what() << std::endl;
    }
	
    std::cout << "\n=== Test 4: RobotomyRequestForm - Sign, can't execute and execute ===\n";
    try {
		bob.signForm(robot);
        bob.executeForm(robot);
		david.executeForm(robot);
    } 
	catch (std::exception &e) {
    	std::cout << e.what() << std::endl;
    }

    // Presidential Pardon
    std::cout << "\n=== Test 5: PresidentialPardonForm - Can't execute, sign, can't execute and execute ===\n";
    try {
        bob.executeForm(pardon);
    	alice.signForm(pardon);
        bob.executeForm(pardon);
        alice.executeForm(pardon);
    } 
	catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    // Test grade too low
        std::cout << "\n=== Test 6: Form already signed and Grade Too Low Test ===\n";
    try {
        charlie.signForm(shrub);
        
        ShrubberyCreationForm shrub1("home1");
        std::cout << shrub1 << std::endl;
        charlie.signForm(shrub1);
        charlie.executeForm(shrub);
    } 
	catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}