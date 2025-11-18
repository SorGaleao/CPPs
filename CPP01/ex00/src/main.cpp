/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:56:31 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/11/18 16:27:35 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
		return (1);
	std::string name = argv[1];
	randomChump(name);
	return 0;
}