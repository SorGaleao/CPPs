/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:47:20 by gabrsouz          #+#    #+#             */
/*   Updated: 2025/12/04 14:18:35 by gabrsouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phonebook.hpp"
#include "../include/contacts.hpp"
#include <cstdlib>

void print_welcome(void)
{
	std::cout << "-------------------------------" << std::endl;
	std::cout << "|                             |" << std::endl;
	std::cout << "|  WELCOME TO YOUR PHONEBOOK! |" << std::endl;
	std::cout << "|                             |" << std::endl;
}

void print_options(void)
{
	std::cout << "-------------------------------\n|  PLEASE, CHOOSE AN OPTION:  |" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	std::cout << "|  ADD                        |" << std::endl;
	std::cout << "|  SEARCH                     |" << std::endl;
	std::cout << "|  EXIT                       |" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	std::cout << "> ";
}



Contact create_contact(Contact& new_contact)
{
	std::string input;
	std::cout << "FIRST NAME: ";
	std::getline(std::cin, input);
	new_contact.setFirstName(input);
	std::cout << "LAST NAME: ";
	std::getline(std::cin, input);
	new_contact.setLastName(input);
	std::cout << "NICKNAME: ";
	std::getline(std::cin, input);
	new_contact.setNickname(input);
	std::cout << "PHONENUMBER: ";
	std::getline(std::cin, input);
	new_contact.setPhoneNumber(input);
	std::cout << "DARKEST SECRET: ";
	std::getline(std::cin, input);
	new_contact.setDarkestSecret(input);
	std::cout << "\n";
	std::cout << new_contact.getFirstName() << " " << new_contact.getLastName()
	 << " has been added to your phonebook!" << std::endl;
	 std::cout << "\n";
	return (new_contact);
}

std::string formatFieldFast(const std::string& s) {
    if (s.size() > 10) return s.substr(0,9) + '.';
    return std::string(10 - s.size(), ' ') + s;
}

void display_contacts(Phonebook& phonebook)
{
	std::cout << "\n|  INDEX   |FIRST NAME| LAST NAME| NICKNAME |" << std::endl;
	for (int i = 0; i < phonebook.getN_Contacts(); i++)
	{
		if (i > 7)
			return;
		char number = (i % 10 + '0');
		std::cout << "|         " << number << "|";
		std::cout << formatFieldFast(phonebook.getContact(i).getFirstName()) << "|";
		std::cout << formatFieldFast(phonebook.getContact(i).getLastName()) << "|";
		std::cout << formatFieldFast(phonebook.getContact(i).getNickname()) << "|" << std::endl;
	}
}

void display_infos_contact(const Contact& contact)
{
	std::cout << "\nCONTACT INFORMATION:" << std::endl;
	std::cout << "FIRST NAME: " << contact.getFirstName() << std::endl;
	std::cout << "LAST NAME: " << contact.getLastName() << std::endl;
	std::cout << "NICKNAME: " << contact.getNickname() << std::endl;
	std::cout << "PHONENUMBER: " << contact.getPhoneNumber() << std::endl;
	std::cout << "DARKEST SECRET: " << contact.getDarkestSecret() << std::endl;
	std::cout << "\n";
}

int main(void)
{
	std::string input;
	Contact new_contact;
	Phonebook phonebook;

	phonebook.setN_Contacts(0);
	phonebook.setMaxContacts(8);
	print_welcome();
	while(1)
	{
		print_options();
		if (!std::getline(std::cin, input))
			return (0);
		if (input == "EXIT" || input == "exit")
		{
			std::cout << "GOODBYE, HONEYPIE!" << std::endl;
			return (0);
		}
		else if (input == "ADD" || input == "add")
		{
			new_contact = create_contact(new_contact);
			phonebook.addContact(new_contact);
		}
		else if (input == "SEARCH" || input == "search")
		{	
			if (phonebook.getN_Contacts() == 0)
			{
				std::cout << "\nYOUR PHONEBOOK IS EMPTY! \nPLEASE, ADD A CONTACT FIRST.\n" << std::endl;
				continue ;
			}
			display_contacts(phonebook);
			std::cout << "ENTER THE INDEX OF THE CONTACT YOU WANT TO VIEW: " << std::endl;
			std::getline(std::cin, input);
			int index = std::atoi(input.c_str());
			if (index < 0 || index > 7)
				std::cout << "INDEX OUT OF RANGE, PLEASE, ENTER A VALID INDEX" << std::endl;
			else {
				if (index - 1 > phonebook.getN_Contacts()) {
					std::cout << phonebook.getN_Contacts() << std::endl;
					std::cout << "INDEX OUT OF RANGE, PLEASE, ENTER A VALID INDEX" << std::endl;
				} else 
					display_infos_contact(phonebook.getContact(index));
			}
		}
		else
			std::cout << "\n\t INVALID ENTRY!" << std::endl;
	}
	return (0); 
}