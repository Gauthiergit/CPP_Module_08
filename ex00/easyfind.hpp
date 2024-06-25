/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:52:15 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/25 17:35:25 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

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
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), nb);
	if (it != container.end())
		return (it);
	throw CantFind();
}

#endif