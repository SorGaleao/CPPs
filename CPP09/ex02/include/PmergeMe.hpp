/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:34:38 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/05/12 19:28:59 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
#define PMERGEME_H

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>
#include <ctime>
#include <cstdlib>
#include <iomanip>

class PmergeMe {
	private:
		std::vector<int> input;
		std::vector<int> sortedVec;
		std::deque<int> sortedDeque;
		double timeVec;
		double timeDeque;

		static bool cmpPair(const std::pair<int,int>& x, const std::pair<int,int>& y);
		static std::vector<int> mergeInsertVectorImpl(const std::vector<int>& input);
		static std::deque<int> mergeInsertDequeImpl(const std::vector<int>& input);
		static bool parseInputStr(const std::string& s, std::vector<int>& out);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		bool parseInputStr(const std::string& s);
		void process();
		void printResults() const;
};

#endif
