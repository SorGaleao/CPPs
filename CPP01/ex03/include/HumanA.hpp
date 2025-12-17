/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:59:11 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/12/17 17:55:23 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include <iostream>
#include "../include/Weapon.hpp"

class HumanA {
private:
	const std::string name;
	Weapon &weapon;
public:
	HumanA(const std::string &name, Weapon &weapon);
	~HumanA();
	void attack();
};

#endif