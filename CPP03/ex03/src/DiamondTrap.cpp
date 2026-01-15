/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:05:18 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/15 16:13:56 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	this->name = name;
	this->energyPoints = 50;
	this->hitPoints = 100;
	this->attackDamage = 30;
	std::cout << "DiamondTrap " << name << " constructed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
	this->name = other.name;
	std::cout << "Copy DiamondTrap assignment called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other) {
	std::cout << "Copy DiamondTrap assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
		name = other.name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << name << " was destroyed." << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap is " << name << std::endl;
	std::cout << "ClapTrap is " << ClapTrap::name << std::endl;
}