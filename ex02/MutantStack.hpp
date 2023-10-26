/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 03:07:12 by pszleper          #+#    #+#             */
/*   Updated: 2023/10/26 04:07:07 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <stack>
# include <iterator>

template <typename T, class Container = std::deque<T> >	// T is the type of elements to be stored, and Container the underlying container used to store, deque [double-ended queue] by default)
class MutantStack : public std::stack<T, Container>		// inherit from stack as we want to extend its' functionality
{
	public:
		MutantStack(void) { }
		MutantStack(const MutantStack& other) : std::stack<T, Container>(other)
		{
			*this = other;
		}

		MutantStack&	operator=(const MutantStack& other)
		{
			if (this != &other)
				this->c = other.c;
			return *(this);
		}
		
		~MutantStack(void) { }

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator	begin() { return this->c.begin(); } // c is a member of the stack class that references the underlying container
		iterator	end() { return this->c.end(); }
};

#endif
