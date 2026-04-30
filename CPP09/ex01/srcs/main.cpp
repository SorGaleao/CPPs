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


/*class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  const int len = 5;

  iter( tab, len, print<const int> );
  iter( tab2, len, print<Awesome> );

  return 0;
}*/