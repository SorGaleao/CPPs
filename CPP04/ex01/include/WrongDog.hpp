/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:14:33 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/16 13:15:38 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal {
public:
	WrongDog();
	WrongDog(const WrongDog& other);
	WrongDog& operator=(const WrongDog &other);
	~WrongDog();
	void makeSound() const;
};

#endif