#include "iostream"
#include "fstream"
#include "stdlib.h"

std::string	file_work(char *nameFile)
{
	std::ifstream	file;
	std::string		str;
	char			letter;

	file.open(nameFile);
	if (file.fail())
	{
		std::cout << "Error: file not found or failed" << std::endl;
		exit(0);
	}
	while (!file.eof())
	{
		file >> std::noskipws >> letter;
		str += letter;
	}
	file.close();
	return (str);
}

void	replace(std::string	old_content, std::string new_fname, char *old_world, char *new_world)
{
	std::ofstream	file;
	int				repl = 0;

	file.open(new_fname.c_str());
	if (file.fail())
	{
		std::cout << "Error: can`t create file" << std::endl;
		return ;
	}
	for (int i = 0; i < (int)old_content.length() - 1; i++)
	{
		if (repl <= i && repl != -1)
			repl = old_content.find(old_world, i);
		if (i == repl)
		{
			file << new_world;
			i += std::string(old_world).length() - 1;
		}
		else
			file << old_content[i];
	}
	file.close();
	return ;
}

int	main(int argc, char **strs)
{
	std::string	new_content;
	std::string	new_fname;

	if (argc != 4)
	{
		std::cout << "Wrong input\nUse: <File> <replace_world> <new_world>" << std::endl;
		return (0);
	}
	new_content = file_work(strs[1]);
	new_fname = (std::string(strs[1]) + ".replace");
	replace(new_content, new_fname, strs[2], strs[3]);
	return (0);
}