/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:58:55 by pineau            #+#    #+#             */
/*   Updated: 2024/03/31 13:46:16 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data		data;
	uintptr_t	raw;

	data.str = "Hello";
	data.n = 42;

	raw = Serializer::serialize(&data);
	Serializer::deserialize(raw);
	return 0;	
}