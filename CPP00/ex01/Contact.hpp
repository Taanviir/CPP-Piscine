#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact {
public:
	Contact(void) {};
	~Contact(void) {};

	// getters for private members
	std::string getFirstName(void) {return this->_firstName;};
	std::string getLastName(void) {return this->_lastName;};
	std::string getNickName(void) {return this->_nickname;};
	std::string getPhoneNumber(void) {return this->_phoneNumber;};
	std::string getDarkestSecret(void) {return this->_darkestSecret;};

	// setters for private members
	void setFirstName(std::string newFirstName) {_firstName = newFirstName;};
	void setLastName(std::string newLastName) {_lastName = newLastName;};
	void setNickname(std::string newNickname) {_nickname = newNickname;};
	void setPhoneNumber(std::string newPhoneNumber) {_phoneNumber = newPhoneNumber;};
	void setDarkestSecret(std::string newDarkestSecret) {_darkestSecret = newDarkestSecret;}

private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;
};

#endif