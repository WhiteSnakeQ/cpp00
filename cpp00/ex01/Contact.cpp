#include "Contact.hpp"
#include "stdlib.h"
Contact::Contact(void)
{
	_index = 0;
}

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone ,std::string secret, size_t index) :
	_index(index),
	_first_name(first_name),
	_last_name(last_name),
	_nickname(nickname),
	_phone(phone),
	_secret(secret)
{

}

Contact::~Contact(void)
{

}

std::string Contact::get_one_line(std::string str)
{
	std::string	to_ret;

	std::cout << str;
	std::getline(std::cin >> std::ws, to_ret);
	return (to_ret);
}

void Contact::set_up_contact(size_t index)
{
	_index = index;
	_first_name = this->get_one_line("Enter first name: ");
	if (_first_name.length() <= 0)
		return ;
	_last_name = this->get_one_line("Enter last name: ");
	if (_last_name.length() <= 0)
		return ;
	_nickname = this->get_one_line("Enter nickname: ");
	if (_nickname.length() <= 0)
		return ;
	_phone = this->get_one_line("Enter phone: ");
	if (_phone.length() <= 0)
		return ;
	_secret = this->get_one_line("Enter secret: ");
	std::cout << std::endl;
}

void	Contact::show(void)
{
	std::cout << "Index: " << _index << std::endl;
	std::cout << "First name: " << _first_name << std::endl;
	std::cout << "Last name: " << _last_name << std::endl;
	std::cout << "Nick name: " << _nickname << std::endl;
	std::cout << "Phone: " << _phone << std::endl;
	std::cout << "Secret: " << _secret << std::endl;
	std::cout << std::endl;
}

std::string Contact::get_first_name(void)
{
	return (_first_name);
}

std::string Contact::get_last_name(void)
{
	return (_last_name);
}

std::string Contact::get_nickname(void)
{
	return (_nickname);
}

size_t Contact::get_index(void)
{
	return (_index);
}
