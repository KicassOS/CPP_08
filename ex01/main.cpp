/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 02:09:02 by pszleper          #+#    #+#             */
/*   Updated: 2023/10/26 03:10:41 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	try
	{
		std::cout << "Test from subject using unsigned int N constructor" << std::endl;
		Span span = Span(5);

		span.addNumber(6);
		span.addNumber(3);
		span.addNumber(17);
		span.addNumber(9);
		span.addNumber(11);
	
		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "\nTesting void constructor Span" << std::endl;
		Span span1;
		std::cout << span1.shortestSpan() << std::endl;
		std::cout << span1.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "\nTesting addNumberRange and addNumber()" << std::endl;
		Span span2(5);
		std::vector<int> vec;

		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		span2.addNumberRange(vec.begin(), vec.end());
		span2.addNumber(2);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	 try
	{
		std::cout << "\nTesting 100000 Span with vector containing 100000 elements" << std::endl;
		Span sp3(100000);
		std::vector<int> vec;
		for (int i = 0; i < 100000; i++)
			vec.push_back(i);
		sp3.addNumberRange(vec.begin(), vec.end());
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
