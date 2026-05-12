/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:34:30 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/05/12 20:53:20 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe() : timeVec(0), timeDeque(0) {}

PmergeMe::PmergeMe(const PmergeMe& other) : input(other.input), sortedVec(other.sortedVec), sortedDeque(other.sortedDeque), timeVec(other.timeVec), timeDeque(other.timeDeque) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) { 
	if (this != &other) { 
		input = other.input; 
		sortedVec = other.sortedVec; 
		sortedDeque = other.sortedDeque; 
		timeVec = other.timeVec; 
		timeDeque = other.timeDeque;
	}
	return *this; }
PmergeMe::~PmergeMe() {}

bool PmergeMe::cmpPair(const std::pair<int,int>& x, const std::pair<int,int>& y) { return x.first < y.first; }

bool PmergeMe::parseInputStr(const std::string& s) {
    std::istringstream iss(s);
    std::string token;
    while (iss >> token) {
        if (token[0] == '-' || token.size() > 10) {
            std::cerr << "Error: value must be a positive int. Invalid token: '" << token << "'" << std::endl;
            return false;
        }
        for (size_t i = 0; i < token.size(); ++i) {
            if (!std::isdigit(static_cast<unsigned char>(token[i]))) {
                std::cerr << "Error: invalid token '" << token << "'" << std::endl;
                return false;
            }
        }
        try {
            int val = std::atoi(token.c_str());
            input.push_back(val);
        } catch (const std::exception& e) {
            std::cerr << "Error: invalid number '" << token << "'" << std::endl;
            return false;
        }
    }
    return !input.empty();
}

int jacobsthal_ft(int n) {
    if (n < 0) return -1;
    if (n == 0) return 0;
    if (n == 1) return 1;
    int a = 0; // J(0)
    int b = 1; // J(1)
    for (int i = 2; i <= n; ++i) {
        int tmp = b + 2 * a;
        a = b;
        b = tmp;
    }
    return b;
}

template <typename Container, typename SmallContainer>
Container handleJS(const Container& bigger, const SmallContainer& smaller) {
    Container result(bigger.begin(), bigger.end());
    size_t m = smaller.size();
    if (m == 0) return result;

    std::vector<int> jac;
    for (int k = 1;; ++k) {
        int j = jacobsthal_ft(k);
        if (j <= 0) break;
        if ((size_t)j > m) break;
        int idx = j - 1;
        if (jac.empty() || jac.back() != idx)
            jac.push_back(idx);
    }

    std::vector<bool> used(m, false);
    std::vector<size_t> order;
    for (int i = (int)jac.size() - 1; i >= 0; --i) {
        order.push_back(static_cast<size_t>(jac[i]));
        used[jac[i]] = true;
    }
    for (size_t i = 0; i < m; ++i) if (!used[i]) order.push_back(i);


    for (size_t idx = 0; idx < order.size(); ++idx) {
        int val = smaller[order[idx]];
        typename Container::iterator it = std::lower_bound(result.begin(), result.end(), val);
        result.insert(it, val);
    }

    return result;
}

std::vector<int> handleVec(std::vector<int> &input){
	std::vector<int> empty;
    size_t n = input.size();
    if (n == 0) return empty;
    if (n == 1) return input;

    // create the pairs and sort inside
    std::vector< std::pair<int,int> > pairs;
	for (size_t i = 0; i + 1 < n; i += 2) {
        int a = input[i]; 
		int b = input[i + 1]; 
		if (a > b) 
			std::swap(a, b);
        pairs.push_back(std::make_pair(a,b));
    }

    // separate into bigger (first) and smaller (second) vectors, since its already sorted
    std::vector<int> bigger, smaller;
    for (size_t j = 0; j < pairs.size(); ++j) {
        smaller.push_back(pairs[j].first);
		bigger.push_back(pairs[j].second);
    }
	
    // if odd number of elements, add the last unpaired element to 'bigger'
    if (n % 2 == 1)
        bigger.push_back(input[n - 1]);

    std::vector<int> sortedBigger = handleVec(bigger);
    std::vector<int> merged = handleJS(sortedBigger, smaller);
    return merged;
}

std::deque<int> handleDeque(std::deque<int> input) {
	std::deque<int> excep;
    size_t n = input.size();
    if (n == 0) return excep;
    if (n == 1) return input;

	// create the pairs and sort inside
    std::deque< std::pair<int,int> > pairs;
	for (size_t i = 0; i + 1 < n; i += 2) {
        int a = input[i]; 
		int b = input[i + 1]; 
		if (a > b) 
			std::swap(a, b);
        pairs.push_back(std::make_pair(a,b));
    }


    // separate into bigger (first) and smaller (second) vectors, since its already sorted
    std::deque<int> bigger, smaller;
    for (size_t j = 0; j < pairs.size(); ++j) {
        smaller.push_back(pairs[j].first);
		bigger.push_back(pairs[j].second);
    }
	
    // if odd number of elements, add the last unpaired element to 'bigger'
    if (n % 2 == 1)
        bigger.push_back(input[n - 1]);

    std::deque<int> sortedBigger = handleDeque(bigger);
    std::deque<int> merged = handleJS(sortedBigger, smaller);
    return merged;
}

void PmergeMe::process() {
    std::vector<int> tmp1 = input;
    clock_t start = std::clock();
    sortedVec = handleVec(tmp1);
    clock_t end = std::clock();
    timeVec = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    std::deque<int> tmp2(tmp1.begin(), tmp1.end());
    clock_t start1 = std::clock();
    sortedDeque = handleDeque(tmp2);
    clock_t end1 = std::clock();
    timeDeque = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC;
}

void PmergeMe::printResults() const {
    std::cout << "Before: ";
    for (size_t i = 0; i < input.size(); ++i) {
        if (i) std::cout << ' ';
        std::cout << input[i];
    }
    std::cout << std::endl;

    std::cout << "After: ";
    for (size_t i = 0; i < sortedVec.size(); ++i) {
        if (i) std::cout << ' ';
        std::cout << sortedVec[i];
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << sortedVec.size() << " elements with std::vector : "
              << std::fixed << std::setprecision(7) << timeVec << " s" << std::endl;
    std::cout << "Time to process a range of " << sortedDeque.size() << " elements with std::deque  : "
              << std::fixed << std::setprecision(7) << timeDeque << " s" << std::endl;
}


