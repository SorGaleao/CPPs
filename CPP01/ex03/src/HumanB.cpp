/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:59:17 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/12/17 17:48:41 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"
#include "../include/HumanB.hpp"

HumanB::HumanB(const std::string &human_name) : name(human_name), weapon(NULL) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &new_weapon) {
	weapon = &new_weapon;
}
void HumanB::attack() {
	if (!weapon) {
		std::cout << name << " has no weapon" << std::endl;
		return;
	}
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}