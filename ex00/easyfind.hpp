/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:52:15 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/25 16:08:46 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>

class CantFind : public std::exception
{
	public:

	virtual const char* what() const throw()
	{
		return ("Can't find integer !");
	}
};

template< typename T >
typename T::iterator easyfind(T &container, int nb)
{
	for(std::vector<int>::iterator it = container.begin(); it != container.end(); it++)
	{
		if (*it == nb)
			return (it);
	}
	throw CantFind();
}

#endif