/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmacedo- <hanielhuam@hotmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:28:08 by hmacedo-          #+#    #+#             */
/*   Updated: 2026/11/02 20:28:59 by hmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

class D : public Base {};

int	main(void)
{
	Base	*base = Base::generate();
	Base::identify(base);
	Base::identify(*base);
	delete(base);
	base = new D();
	Base::identify(base);
	Base::identify(*base);
	return (0);
}
