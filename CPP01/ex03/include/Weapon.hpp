/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:59:05 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/12/17 17:53:22 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>
class Weapon {
private:
	std::string type;

public:
	Weapon(std::string type);
	~Weapon();
	const std::string &getType() const;
	void setType(const std::string &waeponType);
};

#endif