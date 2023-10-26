/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 03:07:12 by pszleper          #+#    #+#             */
/*   Updated: 2023/10/26 04:10:46 by pszleper         ###   ########.fr       */
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

		typedef typename std::stack<T, Container>::container_type::iterator iterator;
		iterator	begin() { return static_cast<iterator>(this->c.begin()); } // c is a member of the stack class that references the underlying container
		iterator	end() { return static_cast<iterator>(this->c.end()); }
};

#endif
