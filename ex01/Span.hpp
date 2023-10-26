/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 02:08:59 by pszleper          #+#    #+#             */
/*   Updated: 2023/10/26 03:10:41 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <exception>
# include <algorithm>
# include <vector>

typedef std::vector<int>::iterator  t_IntIter;

class Span
{
	public:
		Span(void);								// canonical
		Span(unsigned int N);
		Span(const Span& other);				// canonical
		Span&	operator=(const Span& other);	// canonical
		~Span(void);							// canonical

		void			addNumber(int value);
		void			addNumberRange(t_IntIter begin, t_IntIter end);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);

		class	FullSpan : public std::exception
		{
			const char* what(void) const throw();
		};

		class	NoSpaceInSpan : public std::exception
		{
			const char* what(void) const throw();
		};

		class	NoRangeInSpan : public std::exception
		{
			const char* what(void) const throw();
		};

	private:
		std::vector<int>	_vector;
};

#endif
