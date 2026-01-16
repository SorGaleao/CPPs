/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:48:11 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/16 15:35:52 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat was created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other.type) {
	std::cout << "Cat copy was created" << std::endl;
}

Cat& Cat::operator=(const Cat &other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat was destroyed" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Miau!" << std::endl;
}