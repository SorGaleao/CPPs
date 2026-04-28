/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:05:43 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/04/28 12:19:59 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other)
			target = other.target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!getIsSigned())
		throw AForm::FormNotSigned();
	if (executor.getGrade() > getGradeToExec())
		throw Bureaucrat::GradeTooLowException();

	std::string filename = target + "_shrubbery";
	std::ofstream ofs(filename.c_str());
	if (!ofs.is_open()) {
		std::cerr << "Failed to open file: " << filename << std::endl;
		throw std::ios_base::failure("Unable to create shrubbery file");
	}

	const char *tree =	"       _-_       \n"
						"    /~~   ~~\\   \n"
						" /~~         ~~\\\n"
						"{               }\n"
						" \\  _-     -_  /\n"
						"   ~  \\  //  ~   \n"
						"_- -   | | _- _  \n"
						"  _ -  | |   -_  \n"
						"      //  \\	  \n";

	// write a few trees
	for (int i = 0; i < 3; ++i) {
		ofs << tree << std::endl;
	}

	ofs.close();
	std::cout << "Shrubbery created: " << filename << std::endl;
}