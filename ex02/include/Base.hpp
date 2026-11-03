/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:27:06 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/11/02 20:27:42 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>

class Base
{
public:
	virtual ~Base();

	static Base	*generate(void);
	static void	identify(Base *base);
	static void	identify(Base &base);
};