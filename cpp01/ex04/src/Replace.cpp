
#include "Replace.hpp"

Replace::Replace(char **argv)
{
	this->_readFile = argv[1];
	this->_writeFile = this->_readFile + ".replace";
	this->_s1 = argv[2];
	this->_s2 = argv[3];
	return ;
}

Replace::~Replace()
{
	return ;
}

bool	Replace::openFiles()
{
	this->_inFile.open(this->_readFile);
	if (this->_inFile.good())
	{
		this->_outFile.open(this->_writeFile);
		if (this->_outFile.good())
			return (1);
		else
		{
			std::cerr << "Opening '" << this->_writeFile << "' failed\n";
			this->_outFile.close();
			this->_inFile.close();
			return (0);
		}
	}
	else
	{
		std::cerr << "opening '" << this->_readFile << "' failed\n";
		this->_inFile.close();
		return (0);
	}
}

bool	Replace::copyFile()
{
	std::string	line;
	std::string	subLine;
	size_t		pos;
	char		end_char;

	if (!this->_inFile.is_open() || !this->_outFile.is_open())
		return (0);
	while (std::getline(this->_inFile, line))
	{
		pos = line.find(this->_s1, 0);
		while (pos != std::string::npos)
		{
			subLine = line.substr(0, pos);
			this->_outFile << subLine << this->_s2;
			line = line.substr(pos + this->_s1.length());
			pos = line.find(this->_s1, 0);
		}
		this->_outFile << line;
		this->_inFile.unget();
		end_char = this->_inFile.get();
		if (end_char == '\n')
			this->_outFile << end_char;
	}
	this->_inFile.close();
	this->_outFile.close();
	return (1);
}
