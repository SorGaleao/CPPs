/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:48:31 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/30 18:17:10 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int main() {
	 try {
        Bureaucrat bob("Bob", 1); // Grade alto (pode executar tudo)
        PresidentialPardonForm form("Arthur Dent");

        bob.signForm(form); // Bob assina o formulário

        bob.executeForm(form); // Bob executa o formulário

    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }
	
	return (0);
}