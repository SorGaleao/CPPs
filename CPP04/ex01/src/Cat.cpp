/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:48:11 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/16 15:47:25 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain()) {
	std::cout << "Cat was created" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "Cat copy was created" << std::endl;
}

Cat& Cat::operator=(const Cat &other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		*brain = *other.brain;
	}
	return (*this);
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat was destroyed" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Miau!" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea) {
	if (brain)
		brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
	if (brain)
		return brain->getIdea(index);
	return "";
}