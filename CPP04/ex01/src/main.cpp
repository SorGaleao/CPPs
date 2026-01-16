/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:19:57 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/16 16:30:12 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongDog.hpp"
#include "../include/WrongCat.hpp"
#include <cstddef>
#include <string>

int main(void) {
	std::cout << "--- Basic polymorphic calls ---" << std::endl; {
	const Animal* base = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "Type dog: " << dog->getType() << std::endl;
	std::cout << "Type cat: " << cat->getType() << std::endl;
	cat->makeSound();
	dog->makeSound();
	base->makeSound();

	delete base;
	delete dog;
	delete cat;
	}
	
	std::cout << "\n--- Array of Animal* ---" << std::endl; {
	const std::size_t packSize = 4;
	const Animal* packMember[packSize] = {
		new Dog(), new Cat(), new Dog(), new Cat()
	};
	for (std::size_t index = 0; index < packSize; ++index) {
		std::cout << "PackMember[" << index << "] is a " << packMember[index]->getType() << " -> ";
		packMember[index]->makeSound();
	}
	for (std::size_t index = 0; index < packSize; ++index) {
		delete packMember[index];
	}
	}

	std::cout << "\n--- Copy Constructor Test ---" << std::endl; {
	Cat originalCat;
	originalCat.setIdea(0, "catnip");
	Cat copiedCat(originalCat);
	std::cout << "Original cat idea[0]: " << originalCat.getIdea(0) << std::endl;
	std::cout << "Another cat idea[0]:  " << copiedCat.getIdea(0) << std::endl;
	originalCat.setIdea(0, "fish");
	copiedCat.setIdea(0, "milk");
	std::cout << "After change the individual ideas" << std::endl;
	std::cout << "Original cat idea[0]: " << originalCat.getIdea(0) << std::endl;
	std::cout << "Copied cat idea[0]:   " << copiedCat.getIdea(0) << std::endl;
	std::cout << "Original cat: ";
	originalCat.makeSound();
	std::cout << "Copied cat: ";
	copiedCat.makeSound();
	}

	std::cout << "\n--- Assignment Operator Test ---" << std::endl; {
	Cat originalCat;
	Cat anotherCat;
	originalCat.setIdea(1, "catnip");
	anotherCat = originalCat;
	std::cout << "Original cat idea[1]: " << originalCat.getIdea(1) << std::endl;
	std::cout << "Another cat idea[1]:  " << anotherCat.getIdea(1) << std::endl;
	std::cout << "After change the individual ideas" << std::endl;
	originalCat.setIdea(1, "tuna");
	anotherCat.setIdea(1, "chicken");
	std::cout << "Original cat idea[1]: " << originalCat.getIdea(1) << std::endl;
	std::cout << "Another cat idea[1]:  " << anotherCat.getIdea(1) << std::endl;
	}

	return 0;
}