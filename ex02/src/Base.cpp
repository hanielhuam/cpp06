/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:32:52 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/11/02 20:33:10 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base	*Base::generate(void)
{
	std::srand(time(NULL));

	switch (std::rand() % 3)
	{
	case 0:
		std::cout << "Class A generated" << std::endl;
		return (new A());
	case 1:
		std::cout << "Class B generated" << std::endl;
		return (new B());
	case 2:
		std::cout << "Class C generated" << std::endl;
		return (new C());
	default:
		std::cout << "Error on class generation" << std::endl;
		exit(1);
	}
}

void	Base::identify(Base *base)
{
	if (dynamic_cast<A*>(base))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(base))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(base))
		std::cout << "C" << std::endl;
	else
		std::cout << "class not identified" << std::endl;
}

void	Base::identify(Base &base)
{
	try
	{
		dynamic_cast<A&>(base);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		dynamic_cast<B&>(base);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception& e) {}
	try
	{
		dynamic_cast<C&>(base);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cout << "class not identified" << std::endl;
	}
}