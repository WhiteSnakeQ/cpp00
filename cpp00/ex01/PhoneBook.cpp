#include "PhoneBook.hpp"
#include "stdlib.h"

PhoneBook::PhoneBook(void)
{
	_index = 0;
}

PhoneBook::~PhoneBook(void)
{

}

void	PhoneBook::fill_all(void)
{
	add(Contact("Kirrill", "Reis", "kreys", "124", "NO SECRET", 1));
	add(Contact("Stas", "Fir", "fox", "124" ,"2", 2));
	add(Contact("Alexx", "Mos", "snake", "124",  "3", 3));
	add(Contact("Stepa", "Pavlov", "bee", "124",  "4", 4));
	add(Contact("Ivan", "Ivanov", "fly", "124",  "5", 5));
	add(Contact("Cerry", "Simv", "plant", "124",  "6", 6));
	add(Contact("Silvi", "So", "Ho 279", "124",  "7", 7));
	add(Contact("Oksana", "Rea", "bf 109 g-14", "124",  "8", 8));
}

void	PhoneBook::choise_index(void)
{
	std::string	index;

	std::cout << "Enter index: ";
	if(!std::getline(std::cin >> std::ws, index))
		return ;
	if (0 >= atoi(index.c_str()) || atoi(index.c_str()) >= 9)
	{
		std::cout << "Invalid index\n" << std::endl;
		return ;
	}
	for (size_t i = 0; i < 8; i++)
	{
		if (atoi(index.c_str()) == (int)_contacts[i].get_index())
		{
			_contacts[i].show();
			return ;
		}
	}
	std::cout << "Unexisting index\n" << std::endl;
}

void	PhoneBook::increase_index(void)
{
	_index += 1;
	if (_index >= 8)
		_index = 0;
}

void	PhoneBook::add(void)
{
	Contact cont;

	cont.set_up_contact(_index + 1);
	_contacts[_index] = cont;
	this->increase_index();
}

void	PhoneBook::add(Contact cont)
{
	_contacts[_index] = cont;
	this->increase_index();
}

void	PhoneBook::search(void)
{
	std::string	index;

	_builder.build_list(_contacts);
	this->choise_index();
}

void	PhoneBook::start(void)
{
	std::string	command;

	_builder.show_message("Welcome to simple PhoneBook");
	_builder.show_avail_comm();
	fill_all();
	while (std::getline(std::cin, command))
	{
		std::cout << std::endl;
		if (command.compare("ADD") == 0)
			this->add();
		else if (command.compare("EXIT") == 0)
			break ;
		else if (command.compare("SEARCH") == 0)
			this->search();
		else
			_builder.show_avail_comm();
	}
	_builder.show_message("Good Luck!");
}
