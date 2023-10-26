/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 02:08:57 by pszleper          #+#    #+#             */
/*   Updated: 2023/10/26 03:10:41 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
{
	_vector.reserve(0);
}

Span::Span(unsigned int N)
{
	_vector.reserve(N);
}

Span::Span(const Span& other)
{
	this->_vector.reserve(other._vector.capacity());
	this->_vector = other._vector;
}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->_vector.clear();
		this->_vector.reserve(other._vector.capacity());
		this->_vector = other._vector;
	}
	return (*this);
}

Span::~Span(void)
{
	_vector.clear();
}

void	Span::addNumber(int value)
{
	if (_vector.size() == _vector.capacity())
		throw FullSpan();
	else
	{
		_vector.push_back(value);
		std::cout << "Added " << value << " to Span" << std::endl;
	}
}

void	Span::addNumberRange(t_IntIter begin, t_IntIter end)
{
	if (begin > end)
		return ;
	if (static_cast<unsigned int>(std::distance(begin, end)) > (_vector.capacity() - _vector.size()))
		throw NoSpaceInSpan();
	else
	{
		_vector.insert(_vector.end(), begin, end);
		std::cout << static_cast<unsigned int>(std::distance(begin, end)) << " numbers added to Span" << std::endl;
	}
}

unsigned int	Span::shortestSpan(void)
{
	if (_vector.size() < 2)
	{
		throw NoRangeInSpan();
		return (-1);
	}
	std::sort(_vector.begin(), _vector.end());
	t_IntIter  start = _vector.begin();
	t_IntIter  end = start + 1;
	unsigned int    shortest = static_cast<unsigned int>(*end - *start);
	for (; end != _vector.end() - 1; ++start, ++end)
	{
		if (static_cast<unsigned int>(*end - *start) < shortest)
			shortest = static_cast<unsigned int>(*end - *start);
	}
	return (shortest);
}

unsigned int	Span::longestSpan(void)
{
	if (_vector.size() < 2)
	{
		throw NoRangeInSpan();
		return (-1);
	}
	std::sort(_vector.begin(), _vector.end());
	t_IntIter  start = _vector.begin();
	t_IntIter  end = _vector.end();
	unsigned int longest = static_cast<unsigned int>(*(end - 1) - *start);
	return (longest);
}

const char* Span::FullSpan::what(void) const throw()
{
	return ("Error: Span is full");
}

const char* Span::NoSpaceInSpan::what(void) const throw()
{
	return ("Error: Not enough space in Span");
}

const char* Span::NoRangeInSpan::what(void) const throw()
{
	return ("Error: Range not found in Span due to there not being enough numbers inside it");
}
