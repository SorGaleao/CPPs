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

#include "../include/whatever.hpp"

int	main(void) {
    int a = 2;
    int b = 3;
	std::cout << "a = " << a << ", b = " << b << std::endl;
    ::swap( a, b );
    std::cout << "swap -> a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
	std::cout << "c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "swap -> c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    return 0;
}

/*int main() {
    std::cout << "=== Test 1: Integers ===" << std::endl;
    int a = 5, b = 10;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::cout << std::endl << "=== Test 2: Doubles ===" << std::endl;
    double x = 3.14, y = 2.71;
    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    ::swap(x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;
    std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
    std::cout << "max(x, y) = " << ::max(x, y) << std::endl;

    std::cout << std::endl << "=== Test 3: Strings ===" << std::endl;
    std::string s1 = "apple", s2 = "banana";
    std::cout << "Before swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;
    ::swap(s1, s2);
    std::cout << "After swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;
    std::cout << "min(s1, s2) = " << ::min(s1, s2) << std::endl;
    std::cout << "max(s1, s2) = " << ::max(s1, s2) << std::endl;

    std::cout << std::endl << "=== Test 4: Equal values ===" << std::endl;
    int e1 = 42, e2 = 42;
    std::cout << "min(e1, e2) = " << ::min(e1, e2) << std::endl;
    std::cout << "max(e1, e2) = " << ::max(e1, e2) << std::endl;

    return 0;
}*/


/*lass Awesome
{
  public:
    Awesome(void) : _n(0) {}
    Awesome( int n ) : _n( n ) {}
    Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
    bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
    bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
    bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
    bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
    bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
    bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
    int get_n() const { return _n; }
  private:
    int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

int main(void)
{
	Awesome a(2), b(4);

        swap(a, b);
        std::cout << a << " " << b << std::endl;
        std::cout << max(a, b) << std::endl;
        std::cout << min(a, b) << std::endl;
        return (0);
}*/
