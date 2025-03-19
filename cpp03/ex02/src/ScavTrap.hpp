
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(const ScavTrap& scavtrap);
	ScavTrap& operator=(const ScavTrap& scavtrap);
	ScavTrap(std::string const& name);
	~ScavTrap();

	void	attack(const std::string& target);
	void	guardGate(void);

private:
	ScavTrap();

};

#endif
