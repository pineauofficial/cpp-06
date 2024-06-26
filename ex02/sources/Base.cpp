/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:47:40 by pineau            #+#    #+#             */
/*   Updated: 2024/04/01 15:28:59 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* Base::generate(void)
{
	srand (time(NULL));
	int i = rand() % 3;
	if (i == 0)
		return std::cout << "A generated" << std::endl, new A;
	else if (i == 1)
		return std::cout << "B generated" << std::endl, new B;
	else
		return std::cout << "C generated" << std::endl, new C;
}

void Base::identify(Base* p) {
	A* a = dynamic_cast<A*>(p);
	B* b = dynamic_cast<B*>(p);
	C* c = dynamic_cast<C*>(p);

	if (a)
		std::cout << "A identified" << std::endl;
	else if (b)
		std::cout << "B identified" << std::endl;
	else if (c)
		std::cout << "C identified" << std::endl;
	else
		std::cout << "Error" << std::endl;
}

void Base::identify(Base& p) {
	int i = 0;
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "A identified" << std::endl;
		(void)a;
		i = 1;
	}
	catch (std::exception &e) {
	}
	try {
		B &b = dynamic_cast<B&>(p);
		std::cout << "B identified" << std::endl;
		(void)b;
		i = 1;
	}
	catch (std::exception &e) {
	}
	try {
		C &c = dynamic_cast<C&>(p);
		std::cout << "C identified" << std::endl;
		(void)c;
		i = 1;
	}
	catch (std::exception &e) {
	}
	if (i == 0)
		std::cout << "Error" << std::endl;
}