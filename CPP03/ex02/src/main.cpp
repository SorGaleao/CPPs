/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:07:28 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/15 16:30:08 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

int main(void)
{
	std::cout << "======= CREATING CLAPTRAP & FRAGTRAP =======" << std::endl; {
	ClapTrap clap("R2D2");
	ScavTrap scav("C3PO");
	FragTrap frag("BB8");
	
	std::cout << "\n======= TESTING ATTACKS =======" << std::endl;
	clap.attack("C3PO");
	clap.attack("BB8");
	scav.attack("R2D2");
	scav.attack("BB8");
	frag.attack("R2D2");
	frag.attack("C3P0");
	
	std::cout << "\n======= TESTING SPECIAL HABILITIES =======" << std::endl;
	scav.guardGate();
	frag.highFivesGuys();
	
	std::cout << "\n======= TESTING TAKE DAMAGE =======" << std::endl;
	clap.takeDamage(5);
	clap.takeDamage(5);
	scav.takeDamage(20);
	scav.takeDamage(30);
	frag.takeDamage(15);
	frag.takeDamage(25);
	
	std::cout << "\n======= TESTING REPAIR =======" << std::endl;
	clap.beRepaired(3);
	scav.beRepaired(15);
	frag.beRepaired(20);
	}
	
	std::cout << "\n======= TESTING SCAVTRAP COPY CONSTRUCTOR =======" << std::endl; {
	FragTrap frag("BB8");
	FragTrap fragCopy(frag);
	fragCopy.attack("Wall-e");
	fragCopy.highFivesGuys();
	std::cout << "\n======= DESTROYING ALL ROBOTS =======" << std::endl;
	}
	
	std::cout << "\n======= TESTING SCAVTRAP ASSIGNMENT =======" << std::endl; {
	FragTrap frag("BB8");
	FragTrap frag2("K-2SO");
	std::cout << "\nBefore assignment:" << std::endl;
	frag2.highFivesGuys();
	frag2.attack("C3PO");
	std::cout << std::endl;
	frag2 = frag;
	std::cout << "\nAfter assignment:" << std::endl;
	frag2.highFivesGuys();
	frag2.attack("C3PO");
	std::cout << "\n======= DESTROYING ALL ROBOTS =======" << std::endl;
	}	
	return 0;
}
