#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
# include <string>

class DiamondTrap: public ScavTrap, public FragTrap {
public:
	DiamondTrap();
	~DiamondTrap();
	DiamondTrap(const DiamondTrap& copy);
	DiamondTrap(std::string name);

	DiamondTrap& operator=(const DiamondTrap& copy);

	void attack(const std::string& target);
	void whoAmI(void);

private:
	std::string _name;
};

#endif