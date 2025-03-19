
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class wrongAnimal
{
public:
	wrongAnimal();
	wrongAnimal(const wrongAnimal& wanimal);
	wrongAnimal& operator=(const wrongAnimal &wanimal);
	wrongAnimal(const std::string& type);
	~wrongAnimal();

	const std::string&	getType() const;
	void				makeSound() const;

protected:
	std::string	_type;

};

#endif