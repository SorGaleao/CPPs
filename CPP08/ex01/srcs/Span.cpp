

#include "../include/Span.hpp"

Span::Span(unsigned int n): capacity(n) {}

Span::Span(const Span& other): capacity(other.capacity), data(other.data) {}

Span& Span::operator=(const Span& other) { 
	if (this != &other) {
	capacity = other.capacity; data = other.data; 
	} return *this; 
}

Span::~Span() {}

void Span::addNumber(int v) {
    if (data.size() >= capacity)
        throw std::runtime_error("Span is full");
    data.push_back(v);
}

std::size_t Span::size() const { return data.size(); }

int Span::shortestSpan() const {
    if (data.size() < 2)
        throw std::runtime_error("Not enough elements");
    std::vector<int> tmp = data;
    std::sort(tmp.begin(), tmp.end());
    int best = std::numeric_limits<int>::max();
    for (std::size_t i = 1; i < tmp.size(); ++i) {
        int diff = tmp[i] - tmp[i-1];
        if (diff < best) best = diff;
    }
    return best;
}

int Span::longestSpan() const {
    if (data.size() < 2)
        throw std::runtime_error("Not enough elements");
    int mn = *std::min_element(data.begin(), data.end());
    int mx = *std::max_element(data.begin(), data.end());
    return mx - mn;
}