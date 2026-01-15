/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:11:57 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/13 15:54:06 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << name << " constructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
	std::cout << "Copy Constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " was destroyed." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	hitPoints -= amount;
	if (hitPoints < 0) 
		hitPoints = 0;
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage." <<std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (energyPoints <= 0 || hitPoints <= 0)
		std::cout << "ClapTrap " << name << " can not attack " << target << std::endl;
	else {
		energyPoints--;
		std::cout << "ClapTrap " << name << " attacks " << target << " , causing " << attackDamage << " points of damage." <<std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energyPoints <= 0 || hitPoints <= 0)
		std::cout << "ClapTrap " << name << " can not attack." << std::endl;
	
	else {
		energyPoints--;
		hitPoints += amount;
		if (hitPoints > 10)
			hitPoints = 10;
		std::cout << "ClapTrap " << name << " is repaired for " << amount << " hit points." << std::endl;
	}
}
