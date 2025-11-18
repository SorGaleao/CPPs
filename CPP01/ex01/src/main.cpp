/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:56:31 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/11/18 16:29:13 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv) {
	if (argc != 3 || !argv[1] || !argv[2])
		return (1);
	int n = atoi(argv[1]);
	if (n <= 0)
		return (1);
	std::string name = argv[2];
	randomChump(name);
	return 0;
}