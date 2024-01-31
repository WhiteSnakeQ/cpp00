#pragma once

#include "Contact.hpp"
#include "string"
# define MAX_SIZE_STR 10
# define COMMANDS "Available command: ADD, EXIT, SEARCH"

class	Builder
{
private:
	void	print_one_str(std::string string);
	void	build_one_contact(Contact cont);
public:
	Builder(void);
	~Builder(void);
	void	show_message(std::string str);
	void	build_list(Contact *conts);
	void	show_avail_comm(void);
};
