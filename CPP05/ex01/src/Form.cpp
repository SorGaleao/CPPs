/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:01:06 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/30 18:35:48 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form(std::string const name,  int const gradeToSign, int const gradeToExec) : name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec) {
	isSigned = false;
}

Form::Form(const Form& other) : name(other.name), isSigned(false), gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec) {}

Form& Form::operator=(const Form &other) {
	if (this != &other) {
		this->isSigned = false;
	}
	return (*this);
}

Form::~Form() {}

std::string Form::getFormName() const { return (name); }
bool Form::getIsSigned() const { return (isSigned); }
int Form::getGradeToSign() const { return (gradeToSign); }
int Form::getGradeToExec() const { return (gradeToExec); }

const char* Form::FormNotSigned::what() const throw() { return ("Form not signed"); }

void Form::beSigned(const Bureaucrat& a) {
	if (a.getGrade() <= gradeToSign)
		isSigned = true;
	else
		throw Bureaucrat::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& a) {
	os << "Form: " << a.getFormName() << "\nSigned: " << a.getIsSigned() << "\nGradeToSign: " << a.getGradeToSign() << "\nGradeToExec: " << a.getGradeToExec() << std::endl;
    return os;
}

