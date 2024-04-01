/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:48:00 by pineau            #+#    #+#             */
/*   Updated: 2024/04/01 15:29:42 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	Base base;
	Base base1;
	std::cout << "-----random Base-----" << std::endl;
	Base* p = base.generate();
	std::cout << "-----Base generated-----" << std::endl;
	Base* p1 = NULL;
	base.identify(p);
	base.identify(*p);
	std::cout << "-----Base NULL-----" << std::endl;
	base1.identify(p1);
	base1.identify(*p1);

	delete p;
	return 0;
}