#pragma once

#include <iostream>

class Contact
{
private:
	size_t		_index;
	std::string _first_name;
	std::string _last_name;
	std::string	_nickname;
	std::string _phone;
	std::string	_secret;
	std::string	get_one_line(std::string);
public:
	Contact(void);
	Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone, \
		std::string secret, size_t index);
	~Contact(void);

	void 		set_up_contact(size_t);
	void		show(void);
	std::string	get_first_name(void);
	std::string	get_last_name(void);
	std::string	get_nickname(void);
	size_t		get_index(void);
};
