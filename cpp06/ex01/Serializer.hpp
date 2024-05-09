#pragma once

#include "iostream"
#include <stdint.h>

typedef struct Data_s
{
	int			serverID;
	int			nUsers;
	std::string	name;
} Data;

class Serializer
{
public:
	static uintptr_t	serialize( Data	*ptr );
	static Data			*deserialize( uintptr_t raw );
};
