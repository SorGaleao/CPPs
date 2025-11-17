/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:12:55 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/11/17 16:42:43 by gabrsouz         ###   ########.fr       */
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
	contacts[getN_Contacts() % getMaxContacts()] = contact;
	setN_Contacts(getN_Contacts() + 1); 
}