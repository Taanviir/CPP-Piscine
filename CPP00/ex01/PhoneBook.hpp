#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook(void);
	~PhoneBook(void);

	void addContact(void);
	void searchContact(void);

	Contact getContact(int index) const {return _contacts[index];};
	void setContact(Contact contact) {_contacts[_contactCount % 8] = contact;};

private:
	Contact _contacts[8];
	int _contactCount; // set on the latest index
};

#endif