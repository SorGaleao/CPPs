/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:19:57 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/16 15:21:30 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongDog.hpp"
#include "../include/WrongCat.hpp"
#include <cstddef>

int main(void) {
	std::cout << "--- Basic polymorphic calls ---" << std::endl;
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

	std::cout << "\n---   WrongAnimals test   ---" << std::endl;
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongDog = new WrongDog();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "Type Wrongdog: " << wrongDog->getType() << std::endl;
	std::cout << "Type Wrongcat: " << wrongCat->getType() << std::endl;
	wrongCat->makeSound();
	wrongDog->makeSound();
	wrongAnimal->makeSound();

	delete wrongAnimal;
	delete wrongDog;
	delete wrongCat;
	
	std::cout << "\n--- Array of Animal* ---" << std::endl;
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

	std::cout << "\n--- Stack objects ---" << std::endl;
	Dog stackDog;
	Cat stackCat;
	stackDog.makeSound();
	stackCat.makeSound();

	return 0;
}