#include "PhoneBook.hpp"
#include <cstdlib>
#include <iomanip>

PhoneBook::PhoneBook() {
	std::cout << "Opening the phone book..." << std::endl;
	_contactCount = 0;
}

PhoneBook::~PhoneBook() {
	std::cout << std::endl << "Destroying the phone book." << std::endl;
}

static std::string getUserInfo(std::string message)
{
	std::string input = "";
	while (true)
	{
		std::cout << message;
		if (!(std::getline(std::cin, input))) {
			if (std::cin.eof()) {
				std::cout << std::endl << "EOF received, quitting program." << std::endl;
				exit(1);
			}
			std::cout << "Error: Invalid input" << std::endl << std::endl;
			continue;
		}
		if (input.empty()) {
			std::cout << "Error: Invalid input" << std::endl << std::endl;
			continue;
		}
		else
			break;
	}
	return input;
}

void PhoneBook::addContact(void) {

	if (_contactCount > 7)
		std::cout << "You have added the maximum possible number of contacts. "
			<< "The contact being added now will overwrite "
			<< getContact(_contactCount % 8).getFirstName() << std::endl;

	Contact newContact;
	newContact.setFirstName(getUserInfo("Enter the Contact's \e[1mFirst Name\e[0m: "));
	newContact.setLastName(getUserInfo("Enter the Contact's \e[1mLast Name\e[0m: "));
	newContact.setNickname(getUserInfo("Enter the Contact's \e[1mNickname\e[0m: "));
	newContact.setPhoneNumber(getUserInfo("Enter the Contact's \e[1mPhone Number\e[0m: "));
	newContact.setDarkestSecret(getUserInfo("Enter the Contact's \e[1mDarkest Secret\e[0m: "));

	setContact(newContact);
	_contactCount++;
	std::cout << "Contact added.✅" << std::endl;
}

static std::string truncate(std::string str) {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void PhoneBook::searchContact(void) {
	if (!_contactCount)
	{
		std::cout << "No contacts to display!" << std::endl;
		return;
	}

	std::cout << "|----------|----------|----------|----------|" << std::endl
		<< "|" << std::setw(10) << std::right << "INDEX"
		<< "|" << std::setw(10) << std::right << "FIRST NAME"
		<< "|" << std::setw(10) << std::right << "LAST NAME"
		<< "|" << std::setw(10) << std::right << "NICKNAME" << "|" << std::endl
		<< "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < (_contactCount > 8 ? 8 : _contactCount); i++) {
		std::cout << "|" << std::setw(10) << std::right << (i + 1)
			<< "|" << std::setw(10) << std::right << truncate(getContact(i).getFirstName())
			<< "|" << std::setw(10) << std::right << truncate(getContact(i).getLastName())
			<< "|" << std::setw(10) << std::right << truncate(getContact(i).getNickname())
			<< "|" << std::endl << "|-------------------------------------------|" << std::endl;
	}

	std::string input;
	while (true)
	{
		std::cout << "Enter the index of the contact to display: ";
		if (!(std::getline(std::cin, input))) {
			if (std::cin.eof()) {
				std::cout << std::endl << "EOF received, quitting program." << std::endl;
				exit(1);
			}
			std::cout << "Error: Invalid input" << std::endl;
			break;
		}
		if (!input.empty() && input.size() == 1 && input >= "1" && input <= "8") {
			if (atoi(input.c_str()) > _contactCount) {
				std::cout << "No contact exists in this index." << std::endl << std::endl;
				continue;
			}
			std::cout << std::endl << "Retrieving information of contact " << input << std::endl;
			(getContact(atoi(input.c_str()) - 1)).printContactInfo();
			break;
		}
		else {
			std::cout << "Error: Invalid input" << std::endl << std::endl;
			continue;
		}
	}
}

Contact PhoneBook::getContact(int index) const {
	return _contacts[index];
}

void PhoneBook::setContact(Contact contact) {
	_contacts[_contactCount % 8] = contact;
}