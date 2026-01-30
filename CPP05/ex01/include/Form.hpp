/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 11:59:54 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/30 18:39:19 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include <string>
#include <iostream>

class Bureaucrat;

class Form {
protected:
	std::string const name;
	bool isSigned;
	int const gradeToSign;
	int const gradeToExec;

public:
	Form(std::string name,  int gradeToSign, int gradeToExec);
	Form(const Form& other);
	Form& operator=(const Form &other);
	~Form();
	void beSigned(const Bureaucrat& a);
	std::string getFormName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	class FormNotSigned : public std::exception {
		public:
			const char* what() const throw();
	};
};


std::ostream& operator<<(std::ostream& os, const Form& a);

#endif