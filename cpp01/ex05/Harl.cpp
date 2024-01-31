#include "Harl.hpp"


Harl::Harl( void )
{
}

Harl::~Harl()
{
}

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-speccial-ketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot belive adding extra bacon cost more money. You didn`t put enough bacon in my burger! If you did, I wouldnt`t be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think i deserue to have some extra bacon for free. I`ve been coming for years whereas you started working here since last month" << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unnacceptable! I want to spek to the manager now." << std::endl;
}

void	Harl::complain( std::string level )
{
	static void	(Harl::*func[4])(void) = {&Harl::error, &Harl::warning, &Harl::info, &Harl::debug};
	static std::string	state[4] = {"ERROR", "WARNING", "INFO", "DEBUG"};
	size_t				i = 0;

	for (size_t j = 0; j < 4; j++, i++)
	{
		if (state[i] == level)
			break;
	}
	if (i == 4)
	{
		std::cout << "Wrong input!" << std::endl;
		return ;
	}
	(this->*func[i])();
}
