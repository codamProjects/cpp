
#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
public:
	Weapon(std::string type);
	~Weapon();

	void				setType(std::string const type);
	std::string const&	getType(void) const;

private:
	std::string _type;

	Weapon();
};

#endif
