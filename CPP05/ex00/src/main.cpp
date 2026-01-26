/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:48:31 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/26 18:12:18 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int main() {
	
	std::cout << "1.--- Grade = 0 ---" << std::endl;
	try {
		Bureaucrat b("Keillin", 0);
		std::cout << b << std::endl;
	} catch (Bureaucrat::GradeTooHighException &e) {
    	std::cerr << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
    	std::cerr << e.what() << std::endl;
	} 

	std::cout << "\n2.--- Grade = -3 ---" << std::endl;
	try {
		Bureaucrat b("Sara", -3);
		std::cout << b << std::endl;
	} catch (Bureaucrat::GradeTooHighException &e) {
    	std::cerr << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
    	std::cerr << e.what() << std::endl;
	} 

	std::cout << "\n3.--- Grade = 7 ---" << std::endl;
	try {
		Bureaucrat b("Ana", 7);
		std::cout << b << std::endl;
	} catch (Bureaucrat::GradeTooHighException &e) {
    	std::cerr << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
    	std::cerr << e.what() << std::endl;
	} 
	
	std::cout << "\n4.--- Grade = 1-- ---" << std::endl;
	try {
		Bureaucrat b("Tania", 1);
		b.gradeIncrementor();
		std::cout << b << std::endl;
	} catch (Bureaucrat::GradeTooHighException &e) {
    	std::cerr << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
    	std::cerr << e.what() << std::endl;
	} 
	
	std::cout << "\n5.--- Grade = 150++ ---" << std::endl;
	try {
		Bureaucrat b("Galeao", 150);
		b.gradeDecrementor();
		std::cout << b << std::endl;
	} catch (Bureaucrat::GradeTooHighException &e) {
    	std::cerr << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
    	std::cerr << e.what() << std::endl;
	} 
	
	std::cout << "\n6.--- Grade = 159 ---" << std::endl;
	try {
		Bureaucrat b("Galeao", 159);
		b.gradeDecrementor();
		std::cout << b << std::endl;
	} catch (Bureaucrat::GradeTooHighException &e) {
    	std::cerr << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
    	std::cerr << e.what() << std::endl;
	} return (0);
}