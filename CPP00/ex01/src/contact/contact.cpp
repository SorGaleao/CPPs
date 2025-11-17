/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:50:04 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/11/17 16:43:40 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/contacts.hpp"

void Contact::setFirstName(std::string value) { 
	FirstName = value; 
}

void Contact::setLastName(std::string value) { 
	LastName = value; 
}

void Contact::setNickname(std::string value) { 
	Nickname = value; 
}

void Contact::setPhoneNumber(std::string value) { 
	PhoneNumber = value; }

void Contact::setDarkestSecret(std::string value) { 
	DarkestSecret = value; 
}

std::string Contact::getFirstName(void) const { 
	return (FirstName); 
}

std::string Contact::getLastName(void) const { 
	return (LastName); 
}

std::string Contact::getNickname(void) const { 
	return (Nickname); 
}

std::string Contact::getPhoneNumber(void) const { 
	return (PhoneNumber); 
}

std::string Contact::getDarkestSecret(void) const { 
	return (DarkestSecret); 
}
