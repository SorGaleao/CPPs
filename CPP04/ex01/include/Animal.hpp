/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:22:25 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/16 10:56:28 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
protected:
	std::string type;

public:
	Animal();
	Animal(std::string type);
	virtual ~Animal();

	std::string getType() const;
	virtual void makeSound() const;
};

#endif