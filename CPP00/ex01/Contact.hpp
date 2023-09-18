#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact {
public:
	Contact(void);
	~Contact(void);

private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNo;
	std::string _darkestSecret;
};

#endif