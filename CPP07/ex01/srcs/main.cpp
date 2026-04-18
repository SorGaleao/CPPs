/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:14:32 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/02/10 17:21:51 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"
#include <iostream>
#include <string>

void printInt(int const &x) { std::cout << x << std::endl; }
void printString(std::string const &x) { std::cout << x << std::endl; }

void increment(int &x) { x += 1; }

int main() {
    int arr[] = {0, 1, 2, 3, 4};
    std::cout << "orig ints:" << std::endl;
    ::iter(arr, 5, printInt);

    std::cout << "after increment:" << std::endl;
    ::iter(arr, 5, increment);
    ::iter(arr, 5, printInt);

    const std::string carr[] = {"one", "two", "three"};
    std::cout << "const strings:" << std::endl;
    ::iter(carr, 3, printString);

    return 0;
}