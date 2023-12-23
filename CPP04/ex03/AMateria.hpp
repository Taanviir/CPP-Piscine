#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria {
public:
	AMateria();
	virtual ~AMateria();
	AMateria(const AMateria& copy);
	AMateria(std::string const* type);
	AMateria(std::string const& type);

	AMateria& operator=(const AMateria& copy);

	std::string const& getType() const; // Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

protected:
	std::string _type;
};

#endif // AMATERIA_HPP
