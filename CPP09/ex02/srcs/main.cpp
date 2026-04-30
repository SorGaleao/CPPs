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
#include <cstdlib>
#include <ctime>

int main() {
    std::cout << "-- test new int() behavior --" << std::endl;
    int *p = new int();
    std::cout << "*p = " << *p << std::endl;
    delete p;

    std::cout << "\n-- default empty array --" << std::endl;
    Array<int> a;
    std::cout << "a.size() = " << a.size() << std::endl;

    std::cout << "\n-- array with size 5 (value-initialized) --" << std::endl;
    Array<int> b(5);
    std::cout << "b.size() = " << b.size() << std::endl;
    for (std::size_t i = 0; i < b.size(); ++i)
        std::cout << "b[" << i << "] = " << b[i] << std::endl;

    std::cout << "\n-- modify and test deep copy (copy ctor) --" << std::endl;
    b[0] = 42;
    Array<int> c(b);
    b[1] = 100;
	std::cout << "b[0] = " << b[0] << ", c[0] = " << c[0] << std::endl;
    std::cout << "b[1] = " << b[1] << ", c[1] = " << c[1] << std::endl;

    std::cout << "\n-- test assignment operator --" << std::endl;
    Array<int> d;
    d = b;
    b[2] = 200;
    std::cout << "b[2] = " << b[2] << ", d[2] = " << d[2] << std::endl;

    std::cout << "\n-- const array and const access --" << std::endl;
    const Array<std::string> sarr(3);
    std::cout << "sarr.size() = " << sarr.size() << std::endl;
    for (std::size_t i = 0; i < sarr.size(); ++i)
        std::cout << "sarr[" << i << "] = '" << sarr[i] << "'" << std::endl;

    std::cout << "\n-- out of bounds access should throw --" << std::endl;
    try {
        std::cout << b[100] << std::endl;
    } catch (const std::exception &e) {
        std::cout << "caught exception: " << e.what() << std::endl;
    }

    return 0;
}

/*#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}*/