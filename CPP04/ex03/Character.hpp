#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"

class Character {
public:
	Character();
	~Character();
	Character(const Character& copy);

	Character& operator=(const Character& copy);

private:
	// AMateria _materias[4];

};

#endif // CHARACTER_HPP
