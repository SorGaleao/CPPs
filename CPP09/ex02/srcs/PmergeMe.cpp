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
        if (token[0] == '-' || token.size() > 9) {
            std::cerr << "Error: value must be a positive int. Invalid token: '" << token << "'" << std::endl;
            return false;
        }
        for (size_t i = 0; i < token.size(); ++i) {
            if (!std::isdigit(static_cast<unsigned char>(token[i]))) {
                std::cerr << "Error: invalid token '" << token << "'" << std::endl;
                return false;
            }
        }
        int val = 0;
        try {
            val = std::stoll(token);
        } catch (const std::exception& e) {
            std::cerr << "Error: invalid number '" << token << "'" << std::endl;
            return false;
        }
        input.push_back(static_cast<int>(val));
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
           if (a > (INT_MAX - b) / 2) return -1; // overflow would occur
           int tmp = b + 2 * a;
        a = b;
        b = tmp;
    }
    return b;
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
	
	//check if even number, if yes, add to the bigger
	if (n % 2 == 1)
		smaller.push_back(input[n]);
	
	// recursive to continuing organazing
	handleVec(bigger);
	
	return input;
}

void	handleDeque(std::vector<int> temp1); {
		
}

void PmergeMe::process() {
	std::vector<int> tmp1 = input;
	handleVec(tmp1);
	std::vector<int> tmp2 = input;
	handleDeque(temp2);
}


