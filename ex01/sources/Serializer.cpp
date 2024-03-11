/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:58:46 by pineau            #+#    #+#             */
/*   Updated: 2024/03/11 17:29:42 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

uintptr_t	Serializer::serialize(Data* ptr) {
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	std::cout << "Pointeur en uintptr_t : " << raw << std::endl;
	return raw;
}

Data*	Serializer::deserialize(uintptr_t raw) {
	Data* ptr = reinterpret_cast<Data*>(raw);
	std::cout << "uintptr_t en pointeur : " << ptr << std::endl;
	return ptr;
}
