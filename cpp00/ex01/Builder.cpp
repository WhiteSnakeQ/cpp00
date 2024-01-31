#include "Builder.hpp"

Builder::Builder(void)
{

}

Builder::~Builder(void)
{

}

void	Builder::print_one_str(std::string string)
{
	if (string.length() >= 10)
	{
		string.resize(9);
		std::cout << string << ".";
	}
	else if (string.length() >= 1)
	{
		std::cout << string;
		for (size_t i = 0; i <  MAX_SIZE_STR - string.length(); i++)
			std::cout << " ";
	}
	else
	{
		std::cout<< "    --    ";
	}
	std::cout << "|";
}

void	Builder::build_one_contact(Contact cont)
{
	std::cout << "|";
	std::cout << cont.get_index() << "         |";
	this->print_one_str(cont.get_first_name());
	this->print_one_str(cont.get_last_name());
	this->print_one_str(cont.get_nickname());
	std::cout << std::endl;
}

void	Builder::build_list(Contact *conts)
{
	std::cout << "|Index     |First Name|Last Name |Nickname  |" << std::endl;
	for (size_t i = 0; i < 8; i++)
		this->build_one_contact(conts[i]);
	std::cout << std::endl;
}

void	Builder::show_avail_comm(void)
{
	std::cout << COMMANDS << std::endl;
}

void	Builder::show_message(std::string str)
{
	size_t		size;

	std::cout << "\n";
	for (size_t i = 0; i < 40; i++)
		std::cout << "-";
	std::cout << std::endl;
	size = (40 - (str.length())) / 2;
	for (size_t i = 0; i < size; i++)
		std::cout << " ";
	std::cout << str;
	for (size_t i = 0; i < size; i++)
		std::cout << " ";
	std::cout << std::endl;
	for (size_t i = 0; i < 40; i++)
		std::cout << "-";
	std::cout << "\n" << std::endl;
}
