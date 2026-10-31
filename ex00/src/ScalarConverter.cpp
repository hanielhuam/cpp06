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
	if (input.size() > 1 && std::isdigit(input[0]))
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

void ScalarConverter::convert (const std::string &input)
{
	if (isChar(input))
		convertFromChar(input);
	//verificar se é número
		//converterfromNumber
	//verificar se é um caso especial (inf e nan)
		//converterFromespecialCase
	//passou das verificações é um tipo desconhecido
}

void ScalarConverter::convertChar(const char &c)
{
	if (!std::isprint(c))
		std::cout << "char: Not printble" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
}

void ScalarConverter::convertInt(const std::string &input)
{
	(void)input;
}

void ScalarConverter::convertFloat(const std::string &input)
{
	(void)input;
}

void ScalarConverter::convertDouble(const std::string &input)
{
	(void)input;
}
