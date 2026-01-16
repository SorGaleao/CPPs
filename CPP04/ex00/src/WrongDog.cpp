/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:17:23 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/16 15:19:44 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal("WrongDog") {
	std::cout << "WrongDog was created" << std::endl;
}

WrongDog::WrongDog (const WrongDog & other) : WrongAnimal(other.type) {
	std::cout << "WrongDog  copy was created" << std::endl;
}

WrongDog& WrongDog ::operator=(const WrongDog  &other) {
	std::cout << "WrongDog copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

WrongDog::~WrongDog() {
	std::cout << "WrongDog was destroyed" << std::endl;
}

void WrongDog::makeSound() const {
	std::cout << "Fua fua!" << std::endl;
}