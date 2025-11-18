/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:42:52 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/11/18 16:28:45 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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

