/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:49:38 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/26 11:55:31 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:

	std::vector<int>	tab;
	unsigned int		_N;

	public:

	class TabFull : public std::exception
	{
		public:

		virtual const char* what() const throw();
	};

	class CantFindDistance : public std::exception
	{
		public:

		virtual const char* what() const throw();
	};

	Span(unsigned int N);
	Span(const Span &copy);
	~Span();

	Span& operator=(const Span &change);

	void addNumber(int nb);
	void addRange(std::vector<int> &range);
	unsigned int shortestSpan();
	unsigned int longestSpan();

};

#endif