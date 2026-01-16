/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:13:08 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/16 16:44:57 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap &other);
	void attack(const std::string& target);
	void guardGate();
};

#endif