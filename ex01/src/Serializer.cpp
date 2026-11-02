/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:08:51 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/11/02 14:09:16 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer &other) {(void)other;}

Serializer::~Serializer(void) {}

Serializer	&Serializer::operator = (const Serializer &other)
{
	(void)other;
	return (*this);
}

uintptr_t	Serializer::serialize(Data *data)
{
	return (reinterpret_cast<uintptr_t>(data));
}

Data	*Serializer::desirialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}