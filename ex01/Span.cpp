/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:30:08 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/26 12:12:40 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &copy)
{
	this->_N = copy._N;
	for (unsigned int i = 0; i < this->_N; i++)
		this->tab[i] = copy.tab[i];
}

Span::~Span() {}

Span& Span::operator=(const Span &change)
{
	this->_N = change._N;
	for (unsigned int i = 0; i < this->_N; i++)
		this->tab[i] = change.tab[i];
	return *this;
}

const char* Span::TabFull::what() const throw()
{
	return ("Span doesn't have enough space :(");
}

const char* Span::CantFindDistance::what() const throw()
{
	return ("Span can't find distance :(");
}

void Span::addNumber(int nb)
{
	if (this->tab.size() < this->_N)
		this->tab.push_back(nb);
	else
		throw Span::TabFull();
}

void Span::addRange(std::vector<int> &range)
{
	if ((range.size() + this->tab.size()) > this->_N)
		throw Span::TabFull();
	else
		this->tab.insert(this->tab.end(), range.begin(), range.end());
}

unsigned int Span::shortestSpan()
{
	if (this->tab.size() < 2)
		throw Span::CantFindDistance();
	std::sort(this->tab.begin(), this->tab.end());
	unsigned int shortest = static_cast<unsigned int>(this->tab.back());
	for (unsigned int i = 0; i + 1 < this->_N; i++)
	{
		if (static_cast<unsigned int>(this->tab[i + 1] - this->tab[i]) < shortest)
			shortest = this->tab[i + 1] - this->tab[i];
	}
	return shortest;
}

unsigned int Span::longestSpan()
{
	if (this->tab.size() < 2)
		throw Span::CantFindDistance();
	std::sort(this->tab.begin(), this->tab.end());
	unsigned int longest = this->tab.back() - this->tab.front();
	return longest;
}