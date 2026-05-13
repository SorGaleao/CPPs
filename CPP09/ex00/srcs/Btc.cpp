/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Btc.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:34:30 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/05/12 14:52:57 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Btc.hpp"

Btc::Btc(std::string name) : fileName(name) {}

Btc::Btc(const Btc& other) : fileName(other.fileName), price(other.price) {}

Btc& Btc::operator=(const Btc& other) {
	if (this != &other) {
		fileName = other.fileName;
		price = other.price;
	}
	return *this;
}

Btc::~Btc() {}

bool processInput(const std::map<std::string, double>& price, const std::string& date_str, double value) {
	std::map<std::string,double>::const_iterator it = price.upper_bound(date_str);
	if (it != price.end() && it->first != date_str) {
		if (it == price.begin()) {
			std::cerr << "Error: no available date <= " << date_str << std::endl;
			return false;
		}
		--it;
	}

	double exchangeRate = it->second * value;
	std::cout << it->first << " => " << value << " = " << exchangeRate << std::endl;
	return true;
}

bool check_values(const std::string& date_str, const std::string& value_str, std::map<std::string, double>& price, const bool db) {
	size_t date_pos1 = date_str.find('-');
	size_t date_pos2 = date_str.find('-', date_pos1 + 1);

	if (date_pos1 == std::string::npos || date_pos2 == std::string::npos) {
		std::cerr << "Error: invalid date format (expected YYYY-MM-DD)" << std::endl;
		return false;
	}

	int year, month, day;
	double value;
	std::istringstream ys(date_str.substr(0, date_pos1));
	std::istringstream ms(date_str.substr(date_pos1 + 1, date_pos2 - date_pos1 - 1));
	std::istringstream ds(date_str.substr(date_pos2 + 1));
	std::istringstream vs(value_str);

	if (!(ys >> year)) { std::cerr << "Error: invalid year => " << date_str << std::endl; return false; }
	if (!(ms >> month)) { std::cerr << "Error: invalid month => " << date_str << std::endl; return false; }
	if (!(ds >> day)) { std::cerr << "Error: invalid day => " << date_str << std::endl; return false; }
	if (!(vs >> value)) { std::cerr << "Error: invalid value =>" << value_str << std::endl; return false; }

	if (year < 2009) { std::cerr << "Error: year before 2009 not allowed" << std::endl; return false; }

	std::map<int, int> monthDays;
	monthDays[1] = 31; monthDays[2] = 28; monthDays[3] = 31; monthDays[4] = 30;
	monthDays[5] = 31; monthDays[6] = 30; monthDays[7] = 31; monthDays[8] = 31;
	monthDays[9] = 30; monthDays[10] = 31; monthDays[11] = 30; monthDays[12] = 31;
	bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
	if (leap)
		monthDays[2] = 29;

	std::map<int,int>::iterator it = monthDays.find(month);
	if (it == monthDays.end()) { std::cerr << "Error: invalid month number" << std::endl; return false; }

	int maxDay = it->second;
	if (day < 1 || day > maxDay) { std::cerr << "Error: invalid day for month" << std::endl; return false; }
	if (value < 0) { std::cerr << "Error: negative value not allowed" << std::endl; return false; }

	// valid -> insert into provided price map when requested
	if (db)
		price[date_str] = value;
	else {
		if (value > 1000) { std::cerr << "Error: value to big" << std::endl; return false; }
		processInput(price, date_str, value);
	}

	return true; // valid

}

bool Btc::parseDb() {
	std::ifstream dbFile(fileName.c_str());
	if (!dbFile.is_open()) {
		std::cerr << "Error: Could not open database file." << std::endl;
		return false;
	}

	std::string line; 
	std::getline(dbFile, line); // To skip header
	
	while (std::getline(dbFile, line)) {
		size_t pos = line.find(',');
		
		if (pos == std::string::npos) {
			std::cerr << "Error: Bad input => " << line << std::endl;
			return false;
		}
		
		std::string date_db = line.substr(0, pos);
		std::string value_db = line.substr(pos + 1);
		if (date_db.empty() || value_db.empty()) {
			std::cerr << "Error: Bad input => " << line << std::endl;
			return false;
		} if (!check_values(date_db, value_db, price, true))
			return false;
	}
	return true;
}

bool Btc::parseInput(std::string input) {
	std::ifstream inputFile(input.c_str());
	if (!inputFile.is_open()) {
		std::cerr << "Error: Could not open database file." << std::endl;
		return false;
	}

	std::string line; 
	std::getline(inputFile, line); // To skip header
	
	while (std::getline(inputFile, line)) {
		size_t pos = line.find('|');
		
		if (pos == std::string::npos) {
			std::cerr << "Error: Bad input => " << line << std::endl;
			continue;
		}
		
		std::string date_input = line.substr(0, pos - 1);
		std::string value_input = line.substr(pos + 2);
		if (date_input.empty() || value_input.empty()) {
			std::cerr << "Error: Bad input => " << line << std::endl;
			continue;
		}
		if (!check_values(date_input, value_input, price, false))
			continue;
	}
	return true;
}