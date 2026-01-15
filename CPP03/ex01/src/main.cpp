/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:07:28 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/15 12:13:02 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"

int main(void)
{
	std::cout << "======= CREATING CLAPTRAP & SCAVTRAP =======" << std::endl;
	ClapTrap clap("R2D2");
	ScavTrap scav("C3PO");
	ClapTrap bb8("BB8");
	
	std::cout << "\n======= TESTING CLAPTRAP ATTACKS =======" << std::endl;
	clap.attack("C3PO");
	clap.attack("BB8");
	
	std::cout << "\n======= TESTING SCAVTRAP ATTACKS =======" << std::endl;
	scav.attack("R2D2");
	scav.attack("BB8");
	
	std::cout << "\n======= TESTING SCAVTRAP GUARDGATE =======" << std::endl;
	scav.guardGate();
	scav.guardGate();
	
	std::cout << "\n======= TESTING TAKE DAMAGE =======" << std::endl;
	clap.takeDamage(5);
	clap.takeDamage(5);
	scav.takeDamage(20);
	scav.takeDamage(30);
	
	std::cout << "\n======= TESTING REPAIR =======" << std::endl;
	clap.beRepaired(3);
	scav.beRepaired(15);
	
	std::cout << "\n======= TESTING SCAVTRAP ENDURANCE =======" << std::endl;
	for (int i = 0; i < 15; i++) {
		scav.attack("Enemy");
	}
	
	std::cout << "\n======= TESTING SCAVTRAP COPY CONSTRUCTOR =======" << std::endl;
	ScavTrap scavCopy(scav);
	scavCopy.attack("Test");
	scavCopy.guardGate();
	
	std::cout << "\n======= TESTING SCAVTRAP ASSIGNMENT =======" << std::endl;
	ScavTrap scav2("K-2SO");
	std::cout << std::endl;
	scav2 = scav;
	scav2.attack("Test2");
	scav2.guardGate();
	
	std::cout << "\n======= DESTROYING ALL ROBOTS =======" << std::endl;
	
	return 0;
}
