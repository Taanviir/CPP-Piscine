#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice {
public:
	Ice();
	~Ice();
	Ice(const Ice& copy);

	Ice& operator=(const Ice& copy);

	AMateria* clone() const;
	void use(ICharacter& target);

private:

};

#endif // ICE_HPP
