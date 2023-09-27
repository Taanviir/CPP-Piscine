#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon {

public:
	Weapon(void) {};
	Weapon(std::string type) : _type(type) {};
	~Weapon(void) {};

	const std::string& getType(void) const;
	void setType(std::string type);

private:
	std::string _type;

};

#endif