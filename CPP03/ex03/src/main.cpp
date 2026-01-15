/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:07:28 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/15 16:24:30 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

int main(void)
{
	std::cout << "======= CREATING ROBOTS =======" << std::endl; {
	ClapTrap clap("R2D2");
	ScavTrap scav("C3PO");
	FragTrap frag("BB8");
	DiamondTrap diamond("K-2SO");
	
	std::cout << "\n======= TESTING ATTACKS =======" << std::endl;
	clap.attack("C3PO");
	scav.attack("BB8");
	frag.attack("K-2SO");
	diamond.attack("R2D2");
	
	std::cout << "\n======= TESTING SPECIAL HABILITIES =======" << std::endl;
	scav.guardGate();
	frag.highFivesGuys();
	diamond.whoAmI();

	std::cout << "\n======= TESTING TAKE DAMAGE =======" << std::endl;
	clap.takeDamage(5);
	scav.takeDamage(15);
	frag.takeDamage(25);
	diamond.takeDamage(35);
	
	std::cout << "\n======= TESTING REPAIR =======" << std::endl;
	clap.beRepaired(3);
	scav.beRepaired(15);
	frag.beRepaired(20);
	diamond.beRepaired(25);
	std::cout << "\n======= DESTROYING ALL ROBOTS =======" << std::endl;
	}
	
	std::cout << "\n======= TESTING DIAMOND COPY CONSTRUCTOR =======" << std::endl; {
	DiamondTrap diamond("K-2SO");
	DiamondTrap diamondCopy(diamond);
	diamondCopy.attack("Test");
	diamondCopy.highFivesGuys();
	std::cout << "\n======= DESTROYING ALL ROBOTS =======" << std::endl;
	}
	
	std::cout << "\n======= TESTING DIAMOND ASSIGNMENT =======" << std::endl; {
	DiamondTrap diamond("K-2SO");
	DiamondTrap diamond2("Wall-e");
	std::cout << "\nBefore assignment:" << std::endl;
	diamond2.whoAmI();
	diamond2.attack("Test_before");
	std::cout << std::endl;
	diamond2 = diamond;
	std::cout << "\nAfter assignment:" << std::endl;
	diamond2.whoAmI();
	diamond2.attack("Test2");
	std::cout << "\n======= DESTROYING ALL ROBOTS =======" << std::endl;
	}
	return 0;
}
