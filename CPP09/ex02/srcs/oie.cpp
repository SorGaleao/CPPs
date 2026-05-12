/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oie.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:34:30 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/05/12 19:33:33 by gabrsouz         ###   ########.fr       */
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

std::vector<int> PmergeMe::mergeInsertVectorImpl(const std::vector<int>& input) {
    std::vector<int> result;
    size_t n = input.size();
    if (n == 0) return result;
    if (n == 1) return input;

    std::vector< std::pair<int,int> > pairs;
    int pend = 0; bool hasPend = false;
    for (size_t i = 0; i + 1 < n; i += 2) {
        int a = input[i]; int b = input[i+1]; if (a < b) std::swap(a,b);
        pairs.push_back(std::make_pair(a,b));
    }
    if (n % 2 == 1) { hasPend = true; pend = input[n-1]; }

    std::sort(pairs.begin(), pairs.end(), cmpPair);

    std::vector<int> mainChain;
    mainChain.reserve(pairs.size() + (hasPend?1:0));
    for (size_t i = 0; i < pairs.size(); ++i) mainChain.push_back(pairs[i].first);

    std::vector<int> smalls(pairs.size());
    for (size_t i = 0; i < pairs.size(); ++i) smalls[i] = pairs[i].second;

    std::vector<size_t> J; J.push_back(0); J.push_back(1);
    while (J.back() < pairs.size()) {
        size_t sz = J.size();
        size_t next = J[sz-1] + 2 * J[sz-2];
        J.push_back(next);
        if (J.size() > 64) break;
    }

    std::vector<bool> used(pairs.size(), false);
    std::vector<size_t> order;
    for (size_t k = 1; order.size() < pairs.size() && k < J.size(); ++k) {
        size_t from = J[k]; size_t prev = J[k-1];
        for (size_t t = from; t > prev; --t) {
            size_t idx = t - 1;
            if (idx < pairs.size() && !used[idx]) { used[idx] = true; order.push_back(idx); }
        }
    }
    for (size_t i = 0; i < pairs.size(); ++i) if (!used[i]) order.push_back(i);

    for (size_t oi = 0; oi < order.size(); ++oi) {
        int v = smalls[order[oi]];
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), v);
        mainChain.insert(it, v);
    }

    if (hasPend) {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend);
        mainChain.insert(it, pend);
    }
    return mainChain;
}

std::deque<int> PmergeMe::mergeInsertDequeImpl(const std::vector<int>& input) {
    std::deque<int> out;
    size_t n = input.size();
    if (n == 0) return out;
    if (n == 1) { out.push_back(input[0]); return out; }

    std::vector< std::pair<int,int> > pairs;
    int pend = 0; bool hasPend = false;
    for (size_t i = 0; i + 1 < n; i += 2) {
        int a = input[i]; int b = input[i+1]; if (a < b) std::swap(a,b);
        pairs.push_back(std::make_pair(a,b));
    }
    if (n % 2 == 1) { hasPend = true; pend = input[n-1]; }

    std::sort(pairs.begin(), pairs.end(), cmpPair);
    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) mainChain.push_back(pairs[i].first);

    std::vector<int> smalls(pairs.size()); for (size_t i = 0; i < pairs.size(); ++i) smalls[i] = pairs[i].second;

    std::vector<size_t> J; J.push_back(0); J.push_back(1);
    while (J.back() < pairs.size()) {
        size_t sz = J.size(); size_t next = J[sz-1] + 2 * J[sz-2]; J.push_back(next); if (J.size() > 64) break;
    }
    std::vector<bool> used(pairs.size(), false); std::vector<size_t> order;
    for (size_t k = 1; order.size() < pairs.size() && k < J.size(); ++k) {
        size_t from = J[k]; size_t prev = J[k-1];
        for (size_t t = from; t > prev; --t) {
            size_t idx = t - 1; if (idx < pairs.size() && !used[idx]) { used[idx] = true; order.push_back(idx); }
        }
    }
    for (size_t i = 0; i < pairs.size(); ++i) if (!used[i]) order.push_back(i);

    for (size_t oi = 0; oi < order.size(); ++oi) {
        int v = smalls[order[oi]];
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), v);
        mainChain.insert(it, v);
    }
    if (hasPend) { std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend); mainChain.insert(it, pend); }
    return mainChain;
}

void PmergeMe::process() {
    std::vector<int> tmp = input;
    std::clock_t sv = std::clock();
    sortedVec = mergeInsertVectorImpl(tmp);
    std::clock_t ev = std::clock();
    timeVec = (double)(ev - sv) / CLOCKS_PER_SEC * 1000000.0;

    std::vector<int> tmp2 = input;
    std::clock_t sd = std::clock();
    sortedDeque = mergeInsertDequeImpl(tmp2);
    std::clock_t ed = std::clock();
    timeDeque = (double)(ed - sd) / CLOCKS_PER_SEC * 1000000.0;
}

void PmergeMe::printResults() const {
    std::cout << "Before: ";
    for (size_t i = 0; i < input.size(); ++i) {
        if (i) std::cout << " "; std::cout << input[i];
    }
    std::cout << std::endl;

    std::cout << "After: ";
    for (size_t i = 0; i < sortedVec.size(); ++i) {
        if (i) std::cout << " "; std::cout << sortedVec[i];
    }
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Time to process a range of " << input.size() << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << input.size() << " elements with std::deque  : " << timeDeque << " us" << std::endl;

}
