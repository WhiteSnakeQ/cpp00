#include "Serializer.hpp"

void	showData( Data *data )
{
	static int	counter = 0;
	if (counter++ % 2 == 0)
		std::cout << "Before" << std::endl;
	else
		std::cout << "After" << std::endl;
	std::cout << "Name -> " << data->name << std::endl;
	std::cout << "Server ID -> " << data->serverID << std::endl;
	std::cout << "Number of users -> " << data->nUsers << std::endl;
}

int	main(void)
{
	Data		data;
	Data		*afterOpr;
	uintptr_t	code;
	data.name = "Toris";
	data.nUsers = 53;
	data.serverID = 1;
	code = Serializer::serialize(&data);
	showData(&data);
	std::cout << "\nUintptr_t code " << code << "\\\n" << std::endl;
	afterOpr = Serializer::deserialize(code);
	showData(afterOpr);
}