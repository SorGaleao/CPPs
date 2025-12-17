/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:59:08 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/12/17 17:55:12 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include <iostream>
#include "../include/Weapon.hpp"

class HumanB {
private:
	const std::string name;
	Weapon *weapon;
public:
	HumanB(const std::string &name);
	~HumanB();
	void setWeapon(Weapon &new_weapon);
	void attack();
};

#endif