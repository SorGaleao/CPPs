/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:42:52 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/15 17:38:44 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("") {}

Zombie::Zombie(std::string n) : name(n) {}

Zombie::~Zombie() {
	if (!name.empty())
		std::cout << name << " was destroyed" << std::endl;
}

void Zombie::setName(std::string n) {
	name = n;
}

std::string Zombie::getZombieName() const { 
    return (name);
}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie(std::string name) {
	return new Zombie(name);
}

void randomChump(std::string name) {
    Zombie zb(name);
    zb.announce();
}

