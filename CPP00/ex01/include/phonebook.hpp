/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:42:59 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/11/17 15:46:26 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contacts.hpp"
#include <iostream>
#include <string>

class Phonebook 
{
	private:
	int N_Contacts;
	int MaxContacts;
	Contact contacts[8];
	
	public:
	//SETTERS
	void setMaxContacts(int value);
	void setN_Contacts(int value);
	void addContact(const Contact& new_contact);
	
	//GETTERS
	int getMaxContacts(void) const;
	int getN_Contacts(void) const;
	const Contact& getContact(int index) const;
};

#endif