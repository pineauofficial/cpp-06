/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:58:55 by pineau            #+#    #+#             */
/*   Updated: 2024/03/11 16:44:27 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Serializer	serializer;
	Data		data;
	uintptr_t	raw;

	data.str = "Hello";
	data.n = 42;

	raw = serializer.serialize(&data);
	serializer.deserialize(raw);
	return 0;	
}