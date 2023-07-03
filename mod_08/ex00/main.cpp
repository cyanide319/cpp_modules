/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 02:11:26 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/07/03 12:29:19 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"easyfind.hpp"
#include<iostream>
#include<vector>
#include<list>
#include<deque>

int main(){
	bool ret;
	std::vector<int>	test1;

	test1.push_back(1);
	test1.push_back(2);
	test1.push_back(3);
	test1.push_back(4);
	test1.push_back(5);

	
	std::cout << "Vector tests" << std::endl;
	ret = easyfind(test1, 5);
	std::cout << std::boolalpha << ret << std::endl;
	ret = easyfind(test1, 6);
	std::cout << std::boolalpha << ret << std::endl;

	std::list<int>	test2;

	test2.push_back(1);
	test2.push_back(2);
	test2.push_back(3);
	test2.push_back(4);
	test2.push_back(5);

	std::cout << std::endl << "list tests" << std::endl;
	ret = easyfind(test2, 1);
	std::cout << std::boolalpha << ret << std::endl;
	ret = easyfind(test2, 6);
	std::cout << std::boolalpha << ret << std::endl;

	std::deque<int>	test3;

	test3.push_back(1);
	test3.push_back(2);
	test3.push_back(3);
	test3.push_back(4);
	test3.push_back(5);

	std::cout << std::endl << "Deque tests" << std::endl;
	ret = easyfind(test3, 3);
	std::cout << std::boolalpha << ret << std::endl;
	ret = easyfind(test3, 6);
	std::cout << std::boolalpha << ret << std::endl;
}