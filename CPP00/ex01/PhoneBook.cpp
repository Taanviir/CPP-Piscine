#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	std::cout << "Opening the phone book..." << std::endl;
	this->_contactCount = 0;
}

PhoneBook::~PhoneBook(void) {
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
			std::cout << "Invalid input" << std::endl;
			continue;
		}
		if (input.empty()) {
			std::cout << "Invalid input" << std::endl << std::endl;
			continue;
		}
		else
			break;
	}
	return input;
}

void PhoneBook::addContact(void) {

	if (this->_contactCount > 7)
		std::cout << "You have added the maximum possible number of contacts. "
			<< "The contact being added now will overwrite "
			<< this->getContact(this->_contactCount % 8).getFirstName() << std::endl;

	Contact newContact;
	newContact.setFirstName(getUserInfo("Enter the Contact's \e[1mFirst Name\e[0m: "));
	newContact.setLastName(getUserInfo("Enter the Contact's \e[1mLast Name\e[0m: "));
	newContact.setNickname(getUserInfo("Enter the Contact's \e[1mNickname\e[0m: "));
	newContact.setPhoneNumber(getUserInfo("Enter the Contact's \e[1mPhone Number\e[0m: "));
	newContact.setDarkestSecret(getUserInfo("Enter the Contact's \e[1mDarkest Secret\e[0m: "));

	this->setContact(newContact);
	this->_contactCount++;
	std::cout << "Contact added.✅" << std::endl;
}

static std::string truncate(std::string str) {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

static void printContactInfo(Contact contact)
{
	std::cout << "Contact's \e[1mFirst Name\e[0m: " << contact.getFirstName() << std::endl;
	std::cout << "Contact's \e[1mLast Name\e[0m: " << contact.getLastName() << std::endl;
	std::cout << "Contact's \e[1mNickname\e[0m: " << contact.getNickname() << std::endl;
	std::cout << "Contact's \e[1mPhone Number\e[0m: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Contact's \e[1mDarkest Secret\e[0m: " << contact.getDarkestSecret() << std::endl;
}

void PhoneBook::searchContact(void) {
	if (!this->_contactCount)
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
	for (int i = 0; i < (this->_contactCount > 8 ? 8 : this->_contactCount); i++) {
		std::cout << "|" << std::setw(10) << std::right << (i + 1)
			<< "|" << std::setw(10) << std::right << truncate(this->getContact(i).getFirstName())
			<< "|" << std::setw(10) << std::right << truncate(this->getContact(i).getLastName())
			<< "|" << std::setw(10) << std::right << truncate(this->getContact(i).getNickname())
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
			std::cout << "Invalid input" << std::endl;
			break;
		}
		if (input.empty())
			continue;
		if (input.size() == 1 && input >= "1" && input <= "8") {
			std::cout << std::endl << "Getting contact " << input << std::endl;
			printContactInfo(this->getContact(std::stoi(input) - 1));
			break;
		}
		else if (std::stoi(input) > this->_contactCount) {
			std::cout << "No contact exists in this index" << std::endl;
			continue;
		}
		else {
			std::cout << "Invalid input" << std::endl;
			continue;
		}
	}
}