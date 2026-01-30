/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 11:59:54 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/30 19:38:03 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H

#include <string>
#include <iostream>

class Bureaucrat;

class AForm {
protected:
	std::string const name;
	bool isSigned;
	int const gradeToSign;
	int const gradeToExec;

public:
	AForm(std::string name,  int gradeToSign, int gradeToExec);
	AForm(const AForm& other);
	AForm& operator=(const AForm &other);
	virtual ~AForm();
	void beSigned(const Bureaucrat& a);
	std::string getFormName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	class FormNotSigned : public std::exception {
		public:
			const char* what() const throw();
	};
	virtual void execute(Bureaucrat const & executor) const = 0;
};


std::ostream& operator<<(std::ostream& os, const AForm& a);

#endif