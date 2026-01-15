/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:07:28 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/15 16:35:25 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"

int main(void)
{
	std::cout << "======= CREATING CLAPTRAP & SCAVTRAP =======" << std::endl; {
	ClapTrap clap("R2D2");
	ScavTrap scav("C3PO");
	
	std::cout << "\n======= TESTING ATTACKS =======" << std::endl;
	clap.attack("C3PO");
	scav.attack("R2D2");
	
	std::cout << "\n======= TESTING SCAVTRAP GUARDGATE =======" << std::endl;
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
		scav.attack("C3PO");
	}
	}
	
	std::cout << "\n======= TESTING SCAVTRAP COPY CONSTRUCTOR =======" << std::endl; {
	ScavTrap scav("BB8");
	ScavTrap scavCopy(scav);
	scavCopy.attack("C3PO");
	scavCopy.guardGate();
	}
	
	std::cout << "\n======= TESTING SCAVTRAP ASSIGNMENT =======" << std::endl; {
	ScavTrap scav("BB8");
	ScavTrap scav2("K-2SO");
	std::cout << std::endl;
	scav2 = scav;
	scav2.attack("C3PO");
	scav2.guardGate();
	}
	
	std::cout << "\n======= TESTING SCAVTRAP ASSIGNMENT =======" << std::endl; {
	ScavTrap scav("BB8");
	ScavTrap scav2("K-2SO");
	std::cout << "\nBefore assignment:" << std::endl;
	scav2.guardGate();
	scav2.attack("C3PO");
	std::cout << std::endl;
	scav2 = scav;
	std::cout << "\nAfter assignment:" << std::endl;
	scav2.guardGate();
	scav2.attack("C3PO");
	std::cout << "\n======= DESTROYING ALL ROBOTS =======" << std::endl;
	}	
	
	return 0;
}
