/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:17:18 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/16 15:12:05 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal was created" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << "WrongAnimal was created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
	std::cout << "WrongAnimal copy was created" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal was destroyed" << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::makeSound() const {
	std::cout << "Ambient sound" << std::endl;
}