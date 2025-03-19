
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
public:
	Character(const Character& src);
	Character& operator=(const Character& src);
	Character(const std::string& name);
	~Character() override;

	std::string const&	getName() const override;
	void				equip(AMateria* m) override;
	void				unequip(int idx) override;
	void				use(int idx, ICharacter& target) override;

	void	addToBin(AMateria* m);
	void	copyBin(AMateria** bin, unsigned int size);

private:
	std::string		_name;
	AMateria*		_inventory[4];
	AMateria**		_bin = nullptr;
	unsigned int	_binSize = 0;
	Character();

};

#endif