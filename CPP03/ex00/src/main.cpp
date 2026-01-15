/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:07:28 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/13 15:55:25 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int main(void)
{
	std::cout << "======= Creating ClapTraps =======" << std::endl;
	ClapTrap robot1("R2D2");
	ClapTrap robot2("C3PO");
	
	std::cout << "\n======= Testing attack =======" << std::endl;
	robot1.attack("C3PO");
	robot1.attack("C3PO");
	
	std::cout << "\n======= Testing takeDamage =======" << std::endl;
	robot2.takeDamage(3);
	robot2.takeDamage(2);
	
	std::cout << "\n======= Testing beRepaired =======" << std::endl;
	robot1.beRepaired(5);
	robot1.beRepaired(3);
	
	std::cout << "\n======= Testing energy depletion =======" << std::endl;
	for (int i = 0; i < 6; i++) {
		robot1.attack("C3PO");
	}
	std::cout << "Trying to attack with no energy:" << std::endl;
	robot1.attack("C3PO");
	
	std::cout << "\n======= Testing copy constructor =======" << std::endl;
	ClapTrap robot3(robot1);
	
	std::cout << "\n======= Testing assignment operator =======" << std::endl;
	ClapTrap robot4("BB8");
	robot4 = robot2;
	
	return 0;
}
