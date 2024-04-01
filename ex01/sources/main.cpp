/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:58:55 by pineau            #+#    #+#             */
/*   Updated: 2024/04/01 15:20:07 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data		data;
	uintptr_t	raw;

	data.str = "Hello";
	data.n = 42;

	std::cout << "adresse data init: " << &data << std::endl;
	raw = Serializer::serialize(&data);
	Serializer::deserialize(raw);
	return 0;	
}