#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "debug.hpp"

class Character: public ICharacter {
public:
	Character();
	~Character();
	Character(const Character& copy);
	Character(std::string const* name);
	Character(std::string const& name);

	Character& operator=(const Character& copy);

	std::string const& getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

private:
	std::string _name;
	AMateria* _materias[4];

};

#endif // CHARACTER_HPP
