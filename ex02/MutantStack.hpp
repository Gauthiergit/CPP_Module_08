/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:43:40 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/26 15:50:32 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack &copy) : std::stack<T>(copy) {}
	~MutantStack() {}

	MutantStack& operator=(const MutantStack &change)
	{
		std::stack<T>::operator=(change);
		return *this;
	}
	
	typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};

#endif