#pragma once
#ifndef __ZOMBIE_H__
# define __ZOMBIE_H__

# include <string>
# include <iostream>
# include <cstdlib>

class Zombie {

public:
	Zombie(void) {};
	~Zombie(void);

	void announce(void);
	void setName(std::string name);

private:
	std::string _name;

};

Zombie* zombieHorde(int N, std::string name);

#endif