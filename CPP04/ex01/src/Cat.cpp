/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:48:11 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/16 10:57:18 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat was created" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat was destroyed" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Miau!" << std::endl;
}