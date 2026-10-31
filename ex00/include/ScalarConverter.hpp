/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 21:12:47 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/10/16 21:13:07 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <cstdlib>
#include <iostream>
#include <limits>

class ScalarConverter
{
	private:
		static bool isChar(const std::string &input);
		static void	convertFromChar(const std::string &input);
		static void convertChar(const char &input);
		static void convertInt(const std::string &input);
		static void convertFloat(const std::string &input);
		static void convertDouble(const std::string &input);
	public:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &other);
		virtual ~ScalarConverter(void) = 0;

		ScalarConverter	&operator = (const ScalarConverter &other);

		static void convert (const std::string &input);
};
