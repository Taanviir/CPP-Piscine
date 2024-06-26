#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap {
public:
	FragTrap();
	~FragTrap();
	FragTrap(const FragTrap& copy);
	FragTrap(std::string* name);
	FragTrap(std::string name);

	FragTrap& operator=(const FragTrap& copy);
	void highFivesGuys(void);

};

#endif