/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:11:57 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/12 15:08:03 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void) {
	std::string debug = "I love having extra bacon for my XL-double-cheese-triple-pickle-special-ketchup burger. \nI really do.";
	std::cout << debug << std::endl;
}

void Harl::info(void) {
	std::string info = "I cannot believe adding extra bacon costs more money. \nYou didnt put enough bacon in my burger! \nIf you did, I wouldnt be asking for more!";
	std::cout << info << std::endl;
}

void Harl::warning(void){
	std::string warning = "I think I deserve to have some extra bacon for free. \nIve been coming for years, whereas you started working here just last month.";
	std::cout << warning << std::endl;
}

void Harl::error(void){
	std::string error = "This is unacceptable! I want to speak to the manager now.";
	std::cout << error << std::endl;
}

void Harl::complain(std::string level) {
	std::string levels[4] = {"debug", "info", "warning", "error"};
	void (Harl::*fts[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (size_t i = 0; i < 4; i++) {
		if (level == levels[i]) {
            (this->*fts[i])();
            return; 
		}
	}
}