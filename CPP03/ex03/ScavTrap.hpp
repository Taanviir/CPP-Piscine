#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap {
public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(const ScavTrap& copy);
	ScavTrap(std::string* name);
	ScavTrap(std::string name);

	ScavTrap& operator=(const ScavTrap& copy);

	void attack(const std::string* target);
	void attack(const std::string& target);
	void guardGate(void);

private:
	bool _guardMode;
};

#endif