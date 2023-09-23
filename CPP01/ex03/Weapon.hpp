#pragma once
#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__

# include <string>
# include <iostream>

class Weapon {

private:
	std::string _type;

public:
	Weapon(std::string type);
	~Weapon(void);

	std::string getType(void);
	void setType(std::string type);

};

#endif