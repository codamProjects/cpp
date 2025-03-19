
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap(const DiamondTrap& diamondtrap);
	DiamondTrap& operator=(const DiamondTrap& diamondtrap);
	DiamondTrap(std::string const& name);
	~DiamondTrap();

	void				whoAmI();
	const std::string&	getName() const;
	using				ScavTrap::attack;

private:
	std::string _name;
	DiamondTrap();
};

#endif