/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Btc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:34:38 by gabrsouz          #+#    #+#             */
/*   Updated: 2026/04/30 18:42:49 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTC_H
#define BTC_H

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Btc {
	private:
		std::string fileName;
		std::map <std::string, double> price;
	
	public:
	Btc(std::string name);
	Btc(const Btc& other);
	Btc& operator=(const Btc& other);
	~Btc();
	bool parseDb();
};

#endif
