/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:21:22 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/16 10:56:12 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal() {
	std::cout << "Animal was created" << std::endl;
}

Animal::Animal(std::string type) : type(type) {
	std::cout << "Animal was created" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal was destroyed" << std::endl;
}
std::string Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
	std::cout << "Random animal sound" << std::endl;
}