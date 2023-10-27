#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

std::string Contact::getFirstName(void) const {
	return _firstName;
}

std::string Contact::getLastName(void) const {
	return _lastName;
}

std::string Contact::getNickname(void) const {
	return _nickname;
}

std::string Contact::getPhoneNumber(void) const {
	return _phoneNumber;
}

std::string Contact::getDarkestSecret(void) const {
	return _darkestSecret;
}

void Contact::setFirstName(std::string newFirstName) {
	_firstName = newFirstName;
}

void Contact::setLastName(std::string newLastName) {
	_lastName = newLastName;
}

void Contact::setNickname(std::string newNickname) {
	_nickname = newNickname;
}

void Contact::setPhoneNumber(std::string newPhoneNumber) {
	_phoneNumber = newPhoneNumber;
}

void Contact::setDarkestSecret(std::string newDarkestSecret) {
	_darkestSecret = newDarkestSecret;
}

void Contact::printContactInfo(void) const {
	std::cout << "Contact's \e[1mFirst Name\e[0m: " << _firstName << std::endl;
	std::cout << "Contact's \e[1mLast Name\e[0m: " << _lastName << std::endl;
	std::cout << "Contact's \e[1mNickname\e[0m: " << _nickname << std::endl;
	std::cout << "Contact's \e[1mPhone Number\e[0m: " << _phoneNumber << std::endl;
	std::cout << "Contact's \e[1mDarkest Secret\e[0m: " << _darkestSecret << std::endl;
}