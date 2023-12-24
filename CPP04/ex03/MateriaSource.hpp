#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"
# include <string>
# include "debug.hpp"

class MateriaSource: public IMateriaSource {
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource& copy);

	MateriaSource& operator=(const MateriaSource& copy);

	void learnMateria(AMateria* materia);
	AMateria* createMateria(std::string const& type);

private:
	AMateria* _materia[4];

};

#endif // MATERIASOURCE_HPP
