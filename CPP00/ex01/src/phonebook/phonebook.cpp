/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:12:55 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/12/09 14:13:04 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/phonebook.hpp"

void Phonebook::setN_Contacts(int value) { 
	N_Contacts = value; }

void Phonebook::setMaxContacts(int value) {
	MaxContacts = value;
}

int Phonebook::getN_Contacts(void) const {
	return (N_Contacts);
}

int Phonebook::getMaxContacts() const  {
	return MaxContacts;
}

const Contact& Phonebook::getContact(int index) const {
	return (contacts[index]);
}

void Phonebook::addContact(const Contact& contact) {
	if (contact.getFirstName().empty() || contact.getLastName().empty() || \
		contact.getNickname().empty() || contact.getPhoneNumber().empty() || \
		contact.getDarkestSecret().empty()) {
		std::cout << "Please, fill all the fields to add a contact to your phonebook!" << std::endl;
		return ;
	} else {
	std::cout << contact.getFirstName() << " " << contact.getLastName()
	 << " has been added to your phonebook!" << std::endl;
	contacts[getN_Contacts() % getMaxContacts()] = contact;
	setN_Contacts(getN_Contacts() + 1);
	}
	return ;
}