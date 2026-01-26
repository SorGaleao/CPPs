/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:21:22 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/26 18:19:00 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) { checkGrade(); };

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other){
	if (this != &other) {
		grade = other.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return (name); }

int Bureaucrat::getGrade() const { return (grade); }

void Bureaucrat::gradeIncrementor() { grade--; checkGrade(); }

void Bureaucrat::gradeDecrementor() { grade++; checkGrade(); }

const char* Bureaucrat::GradeTooHighException::what() const throw() { return ("Grade too high!"); }

const char* Bureaucrat::GradeTooLowException::what() const throw() { return ("Grade too low!"); }

void Bureaucrat::checkGrade() {
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& a) {
	os << "Bureaucrat: " << a.getName() << "\nGrade: " << a.getGrade();
    return os;
}
