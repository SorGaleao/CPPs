/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:17:21 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/16 16:11:50 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat was created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other.type) {
	std::cout << "WrongCat copy was created" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other) {
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat was destroyed" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Uaim!" << std::endl;
}