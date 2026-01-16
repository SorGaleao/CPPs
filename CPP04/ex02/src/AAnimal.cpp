/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:21:22 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/16 12:56:17 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << "AAnimal was created" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
	std::cout << "AAnimal copy was created" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &other) {
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

AAnimal::AAnimal(std::string type) : type(type) {
	std::cout << "AAnimal was created" << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal was destroyed" << std::endl;
}
std::string AAnimal::getType() const {
	return type;
}

void AAnimal::makeSound() const {
	std::cout << "silence" << std::endl;
}