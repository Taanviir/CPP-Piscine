#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "debug.hpp"

class Cure: public AMateria {
public:
	Cure();
	~Cure();
	Cure(const Cure& copy);

	Cure& operator=(const Cure& copy);

	AMateria* clone() const;
	void use(ICharacter& target);

};

#endif // CURE_HPP
