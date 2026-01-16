/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:21:22 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/16 15:09:08 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal() {
	std::cout << "Animal was created" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
	std::cout << "Animal was created" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
	std::cout << "Animal copy was created" << std::endl;
}

Animal& Animal::operator=(const Animal &other) {
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal was destroyed" << std::endl;
}

std::string Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
	std::cout << "Ambient sound" << std::endl;
}