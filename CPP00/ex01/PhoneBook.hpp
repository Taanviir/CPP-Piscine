#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();

	void addContact(void);
	void searchContact(void);

	Contact getContact(int index) const;
	void setContact(Contact contact);

private:
	Contact _contacts[8];
	int _contactCount;
};

#endif