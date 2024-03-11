/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pineau <pineau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:58:35 by pineau            #+#    #+#             */
/*   Updated: 2024/03/11 16:42:03 by pineau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
	std::string str;
	int n;
};

class Serializer
{
	public:

		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
};

#endif