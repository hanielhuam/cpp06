/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 21:05:50 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/10/16 21:12:06 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {(void)other;}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter	&ScalarConverter::operator = (const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

bool ScalarConverter::isChar(const std::string &input)
{
	if (input.size() > 1 || std::isdigit(input[0]))
		return (false);
	return (true);
}

void	ScalarConverter::convertFromChar(const std::string &input)
{
	convertChar(input[0]);
	std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(input[0]) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(input[0]) << std::endl;
}

bool	ScalarConverter::isNumber(const std::string &input)
{
	std::size_t pos;
	
	if (input.find_first_not_of(NUMBERS) != std::string::npos)
		return (false);
	pos = input.find('f');
	if (pos != std::string::npos && pos != input.size() - 1)
		return (false);
	pos = input.find('-');
	if (pos != std::string::npos && (pos != 0 ||
	input.find('-', pos + 1) != std::string::npos))
		return (false);
	pos = input.find('.');
	if (pos != std::string::npos && (pos == 0 || pos == input.size() - 1))
		return (false);
	if (pos != std::string::npos && (input.find('.', pos + 1) != std::string::npos ||
	std::isdigit(input[pos - 1]) == false ||
	std::isdigit(input[pos + 1]) == false))
		return (false);
	return (true);
}

void	ScalarConverter::convertFromNumber(const std::string input)
{
	long double number;

	number = std::strtold(input.c_str(), NULL);
	if (number < -std::numeric_limits<char>::max() ||
	number > std::numeric_limits<char>::max())
		std::cout << "char: overflow" << std::endl;
	else
		convertChar(static_cast<char>(number));
	convertInt(number, input);
	convertFloat(number, input);
	convertDouble(number, input);
}

bool	ScalarConverter::isEspecialCase(const std::string &input)
{
	if (input == "-inf" || input == "+inf" || input == "nan" ||
	input == "-inff" || input == "+inff" || input == "nanf")
		return (true);
	return (false);
}

void	ScalarConverter::convertFromEspecialCase(const std::string &input)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (input.find("nan") != std::string::npos)
	{
    	std::cout << "float: nanf" << std::endl;
    	std::cout << "double: nan" << std::endl;
	}
	else
	{
   		std::cout << "float: " << input[0] << "inff" << std::endl;
    	std::cout << "double: " << input[0] << "inf" << std::endl;
	}
}

void	ScalarConverter::convert (const std::string &input)
{
	if (isChar(input))
		convertFromChar(input);
	else if (isNumber(input))
		convertFromNumber(input);
	if (isEspecialCase(input))
		convertFromEspecialCase(input);
	else
		std::cout << "unknow type" << std::endl;
}

void	ScalarConverter::convertChar(const char &c)
{
	if (!std::isprint(c))
		std::cout << "char: Not printble" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
}

void	ScalarConverter::convertInt(const long double &number, const std::string &input)
{
	if (number < -std::numeric_limits<int>::max() ||
	number > std::numeric_limits<int>::max())
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << std::atoi(input.c_str()) << std::endl;
}

void	ScalarConverter::convertFloat(const long double &number, const std::string &input)
{
	if (number < -std::numeric_limits<float>::max() ||
	number > std::numeric_limits<float>::max())
		std::cout << "float: overflow" << std::endl;
	else
		std::cout << "float: " << std::strtof(input.c_str(), NULL) << "f" << std::endl;
}

void	ScalarConverter::convertDouble(const long double &number, const std::string &input)
{
	if (number < -std::numeric_limits<double>::max() ||
	number > std::numeric_limits<double>::max())
		std::cout << "double: overflow" << std::endl;
	else
		std::cout << "double: " << std::strtod(input.c_str(), NULL) << std::endl;
}
