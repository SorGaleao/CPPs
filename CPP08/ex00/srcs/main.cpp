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

#include "../include/easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
    std::vector<int> v;
    for (int i = 0; i < 10; ++i) v.push_back(i * 2);

    try {
        std::vector<int>::iterator it = easyfind(v, 6);
        std::cout << "found in vector: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cout << "not found in vector: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(v, 7);
        std::cout << "found: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cout << "not found (expected): " << e.what() << std::endl;
    }

    std::list<int> l;
    l.push_back(42);
    l.push_back(7);

    try {
        std::list<int>::iterator it = easyfind(l, 7);
        std::cout << "found in list: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cout << "not found in list: " << e.what() << std::endl;
    }

    return 0;
}
