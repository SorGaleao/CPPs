/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 00:00:00 by automated         #+#    #+#             */
/*   Updated: 2026/04/17 00:00:00 by automated        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cstddef>
#include <limits>

class Span {
private:
    std::size_t capacity;
    std::vector<int> data;

public:
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int v);
    std::size_t size() const;
    int shortestSpan() const;
    int longestSpan() const;

	template <typename It>
	void addNumbers(It begin, It end) {
		std::size_t dist = 0;
		for (It it = begin; it != end; ++it) ++dist;
		if (data.size() + dist > capacity)
			throw std::runtime_error("Not enough space to add range");
		for (It it = begin; it != end; ++it)
			data.push_back(*it);
	}
};

#endif
