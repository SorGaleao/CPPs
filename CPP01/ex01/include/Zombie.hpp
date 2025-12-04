/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:41:31 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/11/20 15:07:11 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
private:
	std::string name;
	int	n;

public:
	Zombie(std::string n) : name(n) {
		std::cout << name << " was created" << std::endl;
	}
	~Zombie() {
		std::cout << name << " was destroied" << std::endl;
	}

	std::string getZombieName() const;
	void announce();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
Zombie* zombieHorde(int N, std::string name);

#endif