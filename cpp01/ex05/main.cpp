#include "Harl.cpp"

int	main(void)
{
	Harl	*harl = new Harl();
	harl->complain("DEBUG");
	harl->complain("INFO");
	harl->complain("WARNING");
	harl->complain("ERROR");
	harl->complain("Lel");
	delete harl;
	return (0);
}