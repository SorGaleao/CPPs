/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:48:09 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/16 15:35:56 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog was created" << std::endl;
}

Dog ::Dog (const Dog & other) : Animal(other.type) {
	std::cout << "Dog  copy was created" << std::endl;
}

Dog & Dog ::operator=(const Dog  &other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog was destroyed" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "auf auf!" << std::endl;
}