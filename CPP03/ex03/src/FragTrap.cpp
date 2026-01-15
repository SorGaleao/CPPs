/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:24:14 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/15 15:45:06 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

FragTrap::FragTrap(std::string nameFrag) : ClapTrap(nameFrag) {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << name << " constructed." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "Copy FragTrap assignment called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other) {
	std::cout << "Copy FragTrap assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

FragTrap::~FragTrap() {
std::cout << "FragTrap " << name << " was destroyed." << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->name << " requested a high-five." << std::endl;
}