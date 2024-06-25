/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:03:57 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/25 16:43:35 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	try
	{
		std::vector<int> container;
		int nb = 4;
		for(int i = 1; i < 7; i++)
			container.push_back(i);
		std::vector<int>::iterator it = container.begin();
		std::vector<int>::iterator itf = easyfind(container, nb);
		std::cout << "Number " << nb << " find at the index " <<
			std::distance(it, itf) << std::endl;
		nb = 7;
		itf = easyfind(container, nb);
		std::cout << "Number " << nb << " find at the index " <<
			std::distance(it, itf) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
