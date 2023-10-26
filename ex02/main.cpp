/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 03:06:43 by pszleper          #+#    #+#             */
/*   Updated: 2023/10/26 04:12:47 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <vector>

int main(void)
{
	MutantStack<int> mstack;

	std::cout << "Pushing 5 and then 17 onto the stack" << std::endl;
	mstack.push(5);
	mstack.push(17);

	std::cout << "\nmstack.top() = " << mstack.top() << std::endl;

	std::cout << "\nPopping the element" << std::endl;
	mstack.pop();

	std::cout << "\nmstack.size() = " << mstack.size() << std::endl;

	std::cout << "\nPushing 3, 5, 737, and finally 0 onto the stack" << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "\nCreating iterators for beginning and end" << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "\nTesting increment and decrement of iterator" << std::endl;

	++it;
	--it;

	std::cout << "\nTesting iterator functionality" << std::endl;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "\nTesting copy constructor into std::stack" << std::endl;
	std::stack<int> s(mstack);
	std::cout << "mstack.top() = " << mstack.top() << "; mstack.size() = " << mstack.size() << std::endl;
	std::cout << "     s.top() = " << s.top() << "     ; s.size() = " << s.size() << std::endl;

	std::cout << "\nTesting copy constructor into MutanStack" << std::endl;
	MutantStack<int> mstack2(mstack);
	MutantStack<int>::iterator itbegin2 = mstack2.begin();
	MutantStack<int>::iterator iteend2 = mstack2.end();
	std::cout << "mstack.top() = " << mstack.top() << "; mstack.size() = " << mstack.size() << std::endl;
	std::cout << "mstack2.top() = " << mstack2.top() << "; mstack2.size() = " << mstack2.size() << std::endl;
	while (itbegin2 != iteend2)
	{
		std::cout << *itbegin2 << std::endl;
		++itbegin2;
	}

	std::cout << "\nTesting assignment constructor into stack" << std::endl;
	MutantStack<int> mstack3 = mstack;
	MutantStack<int>::iterator itbegin3 = mstack3.begin();
	MutantStack<int>::iterator iteend3 = mstack3.end();
	std::cout << "mstack.top() = " << mstack.top() << "; mstack.size() = " << mstack.size() << std::endl;
	std::cout << "mstack2.top() = " << mstack2.top() << "; mstack2.size() = " << mstack2.size() << std::endl;
	while (itbegin3 != iteend3)
	{
		std::cout << *itbegin3 << std::endl;
		++itbegin3;
	}

	std::cout << "\nLet's prove it works on other types and with other containers too" << std::endl;
	MutantStack<std::string, std::vector<std::string> > mstackstring;
	mstackstring.push("Hello");
	mstackstring.push("world");
	mstackstring.push("!");

	std::cout << "\nmstackstring.top() = " << mstackstring.top() << "; mstackstring.size() = " << mstackstring.size() << std::endl;

	std::cout << "\nPopping the element" << std::endl;
	mstackstring.pop();

	std::cout << "\nmstackstring.top() = " << mstackstring.top() << "; mstackstring.size() = " << mstackstring.size() << std::endl;

	std::cout << "\nCreating iterators for beginning and end" << std::endl;

	MutantStack<std::string, std::vector<std::string> >::iterator itstring = mstackstring.begin();
	MutantStack<std::string, std::vector<std::string> >::iterator itestring = mstackstring.end();

	std::cout << "\nTesting increment and decrement of iterator" << std::endl;

	++itstring;
	--itstring;

	std::cout << "\nTesting iterator functionality" << std::endl;

	while (itstring != itestring)
	{
		std::cout << *itstring << std::endl;
		++itstring;
	}

	return (0);
}
