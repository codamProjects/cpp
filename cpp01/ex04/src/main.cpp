
#include "Replace.hpp"

static bool	fileReplacer(char **argv)
{
	Replace replace(argv);

	if (!replace.openFiles())
		return (0);
	if (!replace.copyFile())
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	std::string	buf;

	if (argc != 4)
	{
		std::cerr << "Program needs 3 arguments, " << argc - 1 << " arguments given.\n";
		return (1);
	}
	buf = argv[1];
	if (!buf.length())
	{
		std::cerr << "First argument, the filename, can't be an empty string\n";
		return (1);
	}
	buf = argv[2];
	if (!buf.length())
	{
		std::cerr << "Second argument can't be an emtpy string\n";
		return (1);
	}
	if (!fileReplacer(argv))
		return (1);
	return (0);
}