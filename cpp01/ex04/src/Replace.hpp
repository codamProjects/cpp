
#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>
# include <fstream>
# include <iostream>

class Replace
{
public:
	Replace(char **argv);
	~Replace();

	bool	openFiles();
	bool	copyFile();

private:
	std::ifstream	_inFile;
	std::ofstream	_outFile;
	std::string		_readFile;
	std::string		_writeFile;
	std::string		_s1;
	std::string		_s2;
};

//bool	fileReplacer(char **argv);

#endif
