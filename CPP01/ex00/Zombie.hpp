#pragma once
#ifndef __ZOMBIE_H__
# define __ZOMBIE_H__

# include <string>
# include <iostream>

class Zombie {

public:
	Zombie(void) {_name = "namelessZombie";};
	Zombie(std::string name);
	~Zombie(void);

	void announce(void);

private:
	std::string _name;

};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif