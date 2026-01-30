/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:48:31 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/30 19:37:19 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Intern.hpp"

int main() {
    std::cout << "\n--- Teste 1: Bureaucrat executando PresidentialPardonForm ---\n";
    try {
        Bureaucrat bob("Bob", 1);
        PresidentialPardonForm form1("Arthur Dent");
        bob.signForm(form1);
        bob.executeForm(form1);
    } catch (const std::exception& e) {
        std::cout << "Erro inesperado: " << e.what() << std::endl;
    }

    std::cout << "\n--- Teste 2: Bureaucrat com grade insuficiente ---\n";
    try {
        Bureaucrat joe("Joe", 150);
        PresidentialPardonForm form2("Ford Prefect");
        joe.signForm(form2); // Não deve conseguir assinar
        joe.executeForm(form2); // Não deve conseguir executar
    } catch (const std::exception& e) {
        std::cout << "Erro inesperado: " << e.what() << std::endl;
    }

    std::cout << "\n--- Teste 3: Intern criando formulários ---\n";
    try {
        Bureaucrat bob("Bob", 1);
        Intern intern;
        AForm* f1 = intern.makeForm("robotomy request", "Marvin");
        if (f1) {
            bob.signForm(*f1);
            bob.executeForm(*f1);
            delete f1;
        }
        AForm* f2 = intern.makeForm("shrubbery creation", "Jardim");
        if (f2) {
            bob.signForm(*f2);
            bob.executeForm(*f2);
            delete f2;
        }
        AForm* f3 = intern.makeForm("formulario desconhecido", "Alvo");
        if (!f3)
            std::cout << "Intern não conseguiu criar o formulário desconhecido.\n";
    } catch (const std::exception& e) {
        std::cout << "Erro inesperado: " << e.what() << std::endl;
    }

    std::cout << "\n--- Teste 4: Executar formulário não assinado ---\n";
    try {
        Bureaucrat bob("Bob", 1);
        PresidentialPardonForm form3("Trillian");
        bob.executeForm(form3);
    } catch (const std::exception& e) {
        std::cout << "Erro esperado: " << e.what() << std::endl;
    }
    return 0;
}