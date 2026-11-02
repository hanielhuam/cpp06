/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:09:34 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/11/02 14:10:29 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int	main(void)
{
	Data	data;
	uintptr_t	ptr;

	data.x = 2;
	data.y = 3;
	data.name = "point";
	std::cout << "before serialization" << std::endl;
	std::cout << "Data.x = " << data.x << std::endl;
	std::cout << "Data.y = " << data.y << std::endl;
	std::cout << "Data.name = " << data.name << std::endl;
	ptr = Serializer::serialize(&data);
	std::cout << "after serialization" << std::endl;
	std::cout << "Data.x = " << *reinterpret_cast<int *>(ptr) << std::endl;
	std::cout << "Data.y = " << *reinterpret_cast<int *>(ptr + sizeof(int)) << std::endl;
	std::cout << "Data.name = " << 
	*reinterpret_cast<std::string *>(ptr + 2 * sizeof(int)) << std::endl;
	data = *Serializer::desirialize(ptr);
	std::cout << "after deserialization" << std::endl;
	std::cout << "Data.x = " << data.x << std::endl;
	std::cout << "Data.y = " << data.y << std::endl;
	std::cout << "Data.name = " << data.name << std::endl;

	return (0);
}
