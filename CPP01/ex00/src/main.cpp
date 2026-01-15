/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:56:31 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/15 17:25:36 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
		return (1);
	Zombie* zb;
	std::string name = argv[1];
	randomChump(name);
	zb = newZombie("Kei");
	zb->announce();
	delete (zb);
	return 0;
}