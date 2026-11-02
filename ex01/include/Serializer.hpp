/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:08:02 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/11/02 14:08:34 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>
#include <string>

struct Data
{
	int			x;
	int			y;
	std::string	name;
};

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer &other);
		~Serializer(void);

		Serializer	&operator = (const Serializer &other);
	public:
		static uintptr_t	serialize(Data *data);
		static Data	*desirialize(uintptr_t raw);
};
