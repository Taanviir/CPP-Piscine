#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	std::cout << "Opening the phone book..." << std::endl;
}

PhoneBook::~PhoneBook(void) {
	std::cout << std::endl << "Closing the phone book." << std::endl;
}

void PhoneBook::addContact() {
	Contact newContact;
	std::string input;

	std::cout << "Enter the Contact's First Name: ";
	if (!(std::getline(std::cin, input)))
		return;
	newContact.setFirstName(input);

	std::cout << "Enter the Contact's Last Name: ";
	if (!(std::getline(std::cin, input)))
		return;
	newContact.setLastName(input);

	std::cout << "Enter the Contact's Nick Name: ";
	if (!(std::getline(std::cin, input)))
		return;
	newContact.setNickname(input);

	std::cout << "Enter the Contact's Phone Number: ";
	if (!(std::getline(std::cin, input)))
		return;
	newContact.setPhoneNumber(input);

	std::cout << "Enter the Contact's Darkest Secret: ";
	if (!(std::getline(std::cin, input)))
		return;
	newContact.setDarkestSecret(input);

	this->setContact(newContact);
	std::cout << "Contact added" << std::endl << std::endl;
}

static std::string truncate(std::string str) {
	if (str.length() > 10)
		return str.resize(9) + ".";
	return str;
}

void PhoneBook::searchContact() {
	std::cout << "|----------|----------|----------|----------|" << std::endl
		<< "|" << std::setw(10) << std::right << "INDEX"
		<< "|" << std::setw(10) << std::right << "FIRST NAME"
		<< "|" << std::setw(10) << std::right << "LAST NAME"
		<< "|" << std::setw(10) << std::right << "NICKNAME" << "|" << std::endl
		<< "|----------|----------|----------|----------|" << std::endl;

	for (int i = 0; i < 8; i++) {
		
	}
	// display contacts in phonebook
}

void PhoneBook::setContact(Contact contact) {
	this->_contacts[this->_index] = contact;
	this->_index = (this->_index + 1) % 8;
}