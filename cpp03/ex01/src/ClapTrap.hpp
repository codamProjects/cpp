
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
public:
	ClapTrap(const ClapTrap &claptrap);
	ClapTrap& operator=(const ClapTrap &claptrap);
	ClapTrap(std::string const& name);
	~ClapTrap();

	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	const std::string&	getName() const;
	unsigned int		getAD() const;
	int					getHP() const;
	int					getEP() const;
	void				printStatus() const;

protected:
	std::string 	_name;
	int				_hp = 10;
	int				_ep = 10;
	unsigned int	_ad = 0;

	ClapTrap();

};

#endif