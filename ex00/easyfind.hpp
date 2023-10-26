/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 00:02:20 by pszleper          #+#    #+#             */
/*   Updated: 2023/10/26 03:10:41 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>

class	NoOccurrenceFound : public std::exception
{
	const char* what() const throw()
	{
		return ("Error: No occurrence was found");
	}
};

template <typename T>
void	easyfind(const T& container, int key)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), key);
	if (it == container.end())
	{
		throw NoOccurrenceFound();
	}
	else
	{
		std::cout << "Found occurrence of " << key << " at index " << it - container.begin() << std::endl;
	}
}

#endif
