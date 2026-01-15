/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:14:52 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/15 15:45:12 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string nameScav) : ClapTrap(nameScav) {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this-> attackDamage = 20;
	std::cout << "ScavTrap " << name << " constructed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "Copy ScavTrap assignment called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "Copy ScavTrap assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name << " was destroyed." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (energyPoints <= 0 || hitPoints <= 0)
		std::cout << "ScavTrap " << name << " can not attack " << target << std::endl;
	else {
		energyPoints--;
		std::cout << "ScavTrap " << name << " attacks " << target << " , causing " << attackDamage << " points of damage." <<std::endl;
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}