/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:47:20 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/30 19:39:00 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"


AForm* Intern::makeForm(std::string formName, std::string target) {
    const std::string formNames[] = {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };

    int i = 0;
	
    for (; i < 3; ++i) {
        if (formName == formNames[i])
            break;
    }
	
    switch (i) {
        case 0: {
			std::cout << "Intern creates " << formName << std::endl;
			return new PresidentialPardonForm(target);
		} case 1: {
			std::cout << "Intern creates " << formName << std::endl;
            return new RobotomyRequestForm(target);
		} case 2: {
			std::cout << "Intern creates " << formName << std::endl;
            return new ShrubberyCreationForm(target);
		} default:
            std::cout << "Intern: Unknown form type!" << std::endl;
        return NULL;
    }
}