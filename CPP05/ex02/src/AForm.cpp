/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:01:06 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/04/28 12:30:41 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm(std::string const name,  int const gradeToSign, int const gradeToExec) : name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec) {
	isSigned = false;
}

AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec) {}

AForm& AForm::operator=(const AForm &other) {
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
	return (*this);
}

AForm::~AForm() {}

std::string AForm::getFormName() const { return (name); }
bool AForm::getIsSigned() const { return (isSigned); }
int AForm::getGradeToSign() const { return (gradeToSign); }
int AForm::getGradeToExec() const { return (gradeToExec); }

const char* AForm::FormNotSigned::what() const throw() { return ("Form not signed"); }

const char* AForm::AlreadySigned::what() const throw() { return ("Form already signed"); }

void AForm::beSigned(const Bureaucrat& a) {
	if (isSigned == true)
		throw AForm::AlreadySigned();
	if (a.getGrade() <= gradeToSign)
		isSigned = true;
	else
		throw Bureaucrat::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& a) {
	os << "Form: " << a.getFormName() << "\nSigned: " << a.getIsSigned() << "\nGradeToSign: " << a.getGradeToSign() << "\nGradeToExec: " << a.getGradeToExec() << std::endl;
    return os;
}

