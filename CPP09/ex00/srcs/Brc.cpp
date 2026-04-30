/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brc.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:34:30 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/04/30 18:42:34 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Btc.hpp"

Btc::Btc(std::string name) : fileName(name) {}

Btc::Btc(const Btc& other) : fileName(other.fileName), price(other.price) {}

Btc& Btc::operator=(const Btc& other) {
	if (this != &other) {
		fileName = other.fileName;
		price = other.price;
	}
	return *this;
}

Btc::~Btc() {}

bool Btc::parseDb() {
	std::ifstream dbFile(fileName.c_str());
	if (!dbFile.is_open()) {
		std::cerr << "Error: Could not open database file." << std::endl;
		return false;
	}
	
}