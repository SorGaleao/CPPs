/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:09:25 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/01/12 11:36:49 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <string>

std::string search_replace(std::string line, const std::string& s1, const std::string& s2) {
	size_t pos = 0;
	while ((pos = line.find(s1, pos)) != std::string::npos) {
		line.erase(pos, s1.size());
		line.insert(pos, s2);
		pos += s2.size();
	}
	return (line);
}

int main(int argc, char **argv) {
	if (argc != 4 || !argv[1] || !argv[2] || !argv[3])
		return (0);
	std::string inFile = argv[1];
	std::ifstream inputFile(inFile.c_str());
	if (!inputFile) {
		std::cerr << "Error: cannot open input file" << std::endl;
		return 1;
	}
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty()) {
		std::cerr << "Error: s1 must not be empty" << std::endl;
		return 1;
	}
	std::string line;
	std::string content;
	while (std::getline(inputFile, line)) {
		content += search_replace(line, s1, s2);
		content += '\n';
	}
	std::string outFile = inFile + ".replace";
	std::ofstream outputFile(outFile.c_str());
	if (!outputFile) {
		std::cerr << "Error: cannot open output file" << std::endl;
		return 1;
	}
	outputFile << content;
	outputFile.close();
	return 0;
}