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

#include "../include/Array.hpp"
#include <iostream>
#include <string>

int main() {
    std::cout << "-- test new int() behavior --" << std::endl;
    int *p = new int();
    std::cout << "*p = " << *p << std::endl;
    delete p;

    std::cout << "-- default empty array --" << std::endl;
    Array<int> a;
    std::cout << "a.size() = " << a.size() << std::endl;

    std::cout << "-- array with size 5 (value-initialized) --" << std::endl;
    Array<int> b(5);
    std::cout << "b.size() = " << b.size() << std::endl;
    for (std::size_t i = 0; i < b.size(); ++i)
        std::cout << "b[" << i << "] = " << b[i] << std::endl;

    std::cout << "-- modify and test deep copy (copy ctor) --" << std::endl;
    b[0] = 42;
    Array<int> c(b);
    b[1] = 100;
    std::cout << "b[1] = " << b[1] << ", c[1] = " << c[1] << std::endl;

    std::cout << "-- test assignment operator --" << std::endl;
    Array<int> d;
    d = b;
    b[2] = 200;
    std::cout << "b[2] = " << b[2] << ", d[2] = " << d[2] << std::endl;

    std::cout << "-- const array and const access --" << std::endl;
    const Array<std::string> sarr(3);
    std::cout << "sarr.size() = " << sarr.size() << std::endl;
    for (std::size_t i = 0; i < sarr.size(); ++i)
        std::cout << "sarr[" << i << "] = '" << sarr[i] << "'" << std::endl;

    std::cout << "-- out of bounds access should throw --" << std::endl;
    try {
        std::cout << b[100] << std::endl;
    } catch (const std::exception &e) {
        std::cout << "caught exception: " << e.what() << std::endl;
    }

    return 0;
}