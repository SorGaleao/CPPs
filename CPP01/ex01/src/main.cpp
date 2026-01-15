/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:56:31 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/15 17:32:53 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

int main(int argc, char **argv) {
	if (argc != 3 || !argv[1] || !argv[2])
		return (1);
	int n = atoi(argv[1]);
	if (n <= 0)
		return (1);
	std::string name = argv[2];
	Zombie* horde = zombieHorde(n, name);
	for (int i = 0; i < n; i++) {
		horde[i].announce();
	}
	delete[] horde;
	
	return 0;
}