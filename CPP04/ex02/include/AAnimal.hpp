/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:22:25 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/16 13:04:11 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal {
protected:
	std::string type;

public:
	AAnimal();
	AAnimal(const AAnimal& other);
	AAnimal& operator=(const AAnimal &other);
	AAnimal(std::string type);
	virtual ~AAnimal();

	std::string getType() const;
	virtual void makeSound() const = 0;
};

#endif