#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook(void);
	~PhoneBook(void);

	void addContact(void);
	void searchContact(void);

	Contact getContact(int index) {return this->_contacts[index];};
	void setContact(Contact contact);

private:
	Contact _contacts[8];
	int _index;
};

#endif