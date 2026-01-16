/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:37:30 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/16 12:02:12 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain() {
	std::cout << "Brain was created" << std::endl;
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < 100; ++i)
		ideas[i] = other.ideas[i];
	std::cout << "Brain copy was created" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; ++i)
			ideas[i] = other.ideas[i];
	}
	std::cout << "Brain copy assignment operator called" << std::endl;
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain was destroyed" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea) {
	if (index < 0 || index >= 100)
		return;
	ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
	if (index < 0 || index >= 100)
		return "";
	return ideas[index];
}