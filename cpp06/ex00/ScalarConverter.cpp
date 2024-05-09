#include "ScalarConverter.hpp"

bool	is_number_f( std::string &numb )
{
	char	point;
	int		pos;

	pos = 0;
	point = 0;
	while (numb[pos] != '\0')
	{
		if (numb[pos] == '-' && pos == 0)
			pos++;
		if (numb[pos] == '.')
		{
			point++;
			if (numb[pos + 1] == '\0' || numb[pos + 1] == 'f')
				return (false);
		}
		else if (numb[pos] == 'f')
		{
			if (numb[pos + 1] != '\0')
				return (false);
			else
			{
				numb.erase(pos);
				return (true);
			}
		}
		else if (numb[pos] < '0' || numb[pos] > '9')
			return (false);
		if (point >= 2)
			return (false);
		pos++;
	}
	return (true);
}

void	toChar( std::string val )
{
	int	number;

	std::cout << "Char: ";
	if (val.length() == 1 && (val[0] < '0' || val[0] > '9'))
	{
		std::cout << "'" << val << "'" << std::endl;
		return ;
	}
	if (val[0] == '-')
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (is_number_f(val))
	{
		if (val.find_first_of('.') != val.npos)
		{
			std::cout << "impossible" << std::endl;
			return ;
		}
		number = std::atoi(val.c_str()) % 127;
		if (number < 32 || number > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << (char)number << "'" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}

void	toInt( std::string val )
{
	std::string	newInt;

	std::cout << "Int: ";
	if (val.length() == 1 && (val[0] < '0' || val[0] > '9'))
		std::cout << (int)val[0] << std::endl;
	else if (is_number_f(val))
	{
		newInt = val.substr(0, val.find_first_not_of("-0123456789"));
		std::cout << newInt << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}

void	toFloat( std::string val )
{
	std::string	newInt;

	std::cout << "Float: ";
	if (val == "nan" || val == "nanf")
	{
		std::cout << "nanf" << std::endl;
		return ;
	}
	if (val == "-inf" || val == "-inff")
	{
		std::cout << "-inff" << std::endl;
		return ;
	}
	if (val == "+inf" || val == "+inff")
	{
		std::cout << "+inff" << std::endl;
		return ;
	}
	if (val.length() == 1 && (val[0] < '0' || val[0] > '9'))
		std::cout << (int)val[0] << ".0f" << std::endl;
	else if (is_number_f(val))
	{
		if (val.find_first_of('.') != val.npos)
			std::cout << val << "f" << std::endl;
		else
			std::cout << val << ".0f" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}

void	toDec( std::string val )
{
	std::string	newInt;

	std::cout << "Double: ";
		if (val == "nan" || val == "nanf")
	{
		std::cout << "nan" << std::endl;
		return ;
	}
	if (val == "-inf" || val == "-inff")
	{
		std::cout << "-inf" << std::endl;
		return ;
	}
	if (val == "+inf" || val == "+inff")
	{
		std::cout << "+inf" << std::endl;
		return ;
	}
	if (val.length() == 1 && (val[0] < '0' || val[0] > '9'))
		std::cout << (int)val[0] << ".0" << std::endl;
	else if (is_number_f(val))
	{
		if (val.find_first_of('.') != val.npos)
			std::cout << val << std::endl;
		else
			std::cout << val << ".0" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}

void	ScalarConverter::convert( std::string val )
{
	toChar(val);
	toInt(val);
	toFloat(val);
	toDec(val);
}


