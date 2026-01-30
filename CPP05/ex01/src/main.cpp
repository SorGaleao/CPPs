/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:48:31 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/30 18:36:52 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main() {
	
	std::cout << "1.--- Grade = 5 and GradeToSign = 7 ---" << std::endl; {
		Bureaucrat b("Keillin", 5);
		std::cout << b << std::endl;
		Form c("letter", 7, 5);
		std::cout << c << std::endl;
		b.signForm(c); 
	} {
		std::cout << "\n2.--- Grade = 5 and GradeToSign = 3 ---" << std::endl;
		Bureaucrat b("Keillin", 5);
		std::cout << b << std::endl;
		Form c("letter", 3, 2);
		std::cout << c << std::endl;
		b.signForm(c); 
	} {
		std::cout << "\n3.--- Grade = 5 and GradeToSign = 5 ---" << std::endl;
		Bureaucrat b("Keillin", 5);
		std::cout << b << std::endl;
		Form c("letter", 5, 2);
		std::cout << c << std::endl;
		b.signForm(c); 
	}
	return (0);
}