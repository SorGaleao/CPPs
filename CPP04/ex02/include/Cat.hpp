/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:24:24 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/16 16:37:27 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
private:
	Brain* brain;
public:
	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat &other);
	~Cat();
	void makeSound() const;
	void setIdea(int index, const std::string& idea);
	std::string getIdea(int index) const;
};

#endif