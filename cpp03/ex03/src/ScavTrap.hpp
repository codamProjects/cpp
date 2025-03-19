
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap(const ScavTrap& scavtrap);
	ScavTrap& operator=(const ScavTrap& scavtrap);
	ScavTrap(std::string const& name);
	~ScavTrap();

	void	attack(const std::string& target);
	void	guardGate(void);

protected:
	int				_SThp = 100;
	int				_STep = 50;
	unsigned int	_STad = 20;

private:
	ScavTrap();

};

#endif
