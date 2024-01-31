#include "Harl.hpp"


Harl::Harl( void )
{
}

Harl::~Harl()
{
}

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-speccial-ketchup burger.\nI really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot belive adding extra bacon cost more money.\nYou didn`t put enough bacon in my burger! If you did, I wouldnt`t be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think i deserue to have some extra bacon for free.\nI`ve been coming for years whereas you started working here since last month" << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unnacceptable!\nI want to spek to the manager now." << std::endl;
}

void	Harl::push_messge(int i)
{
	static void	(Harl::*func[4])(void) = {&Harl::error, &Harl::warning, &Harl::info, &Harl::debug};
	for (int j = i; j >= 0; j--)
	{
		if (j != i)
			std::cout << std::endl;
		(this->*func[j])();
	}
	
}

void	Harl::complain( std::string level )
{
	static std::string	state[4] = {"ERROR", "WARNING", "INFO", "DEBUG"};
	static void	(Harl::*func[4])(void) = {&Harl::error, &Harl::warning, &Harl::info, &Harl::debug};
	size_t				i = 0;

	for (size_t j = 0; j < 4; j++, i++)
	{
		if (state[i] == level)
			break;
	}
	if (i == 4)
	{
		std::cout << "Wrong input! - " << level << std::endl;
		return ;
	}
	switch (i)
	{
	case 3:
		(this->*func[3])();
	case 2:
		if (i >= 3)
			std::cout << std::endl;
		(this->*func[2])();
	case 1:
		if (i >= 2)
			std::cout << std::endl;
		(this->*func[1])();
	case 0:
		if (i >= 1)
			std::cout << std::endl;
		(this->*func[0])();
		break;
	
	default:
		break;
	}
}
