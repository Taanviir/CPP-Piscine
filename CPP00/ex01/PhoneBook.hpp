#ifndef __PHONEBOOK_H__
# define __PHONEBOOK_H__

# include "Contact.hpp"

class PhoneBook {

public:
	PhoneBook(void);
	~PhoneBook(void);

	void addContact(void);
	void searchContact(void);

	Contact getContact(int index) const {return this->_contacts[index];};
	void setContact(Contact contact) {this->_contacts[this->_contactCount % 8] = contact;};

private:
	Contact _contacts[8];
	int _contactCount;

};

#endif