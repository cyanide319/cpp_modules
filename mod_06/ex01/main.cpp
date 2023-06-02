/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:19:09 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/06/01 13:09:37 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdint>
#include <iostream>
#include "color.h"

struct Data{
	int val;
	std::string content;
	std::string name;
};


uintptr_t serialize(Data* ptr){
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw){
	return (reinterpret_cast<Data*>(raw));
}

int main(){
	Data* test1 = new Data();

	test1->content = "Whatever";
	test1->name = "Your mom";
	test1->val = 69;

	std::cout << BOLD ITAL ULINE BG_BRIGHT_BLACK "Data Test 1:" RESET  "\n";
	std::cout << test1->content << std::endl << test1->val << std::endl << test1->name << std::endl;
	
	uintptr_t serial = serialize(test1);
	Data* test2 = deserialize(serial);

	std::cout << BOLD ITAL ULINE BG_BRIGHT_BLACK "Data Test 2:" RESET  "\n";
	std::cout << test2->content << std::endl << test2->val << std::endl << test2->name << std::endl;
	
	uintptr_t serial2 = serialize(test2);
	Data* test3 = deserialize(serial2);

	std::cout << BOLD ITAL ULINE BG_BRIGHT_BLACK "Data Test 3:" RESET  "\n";
	std::cout << test3->content << std::endl << test3->val << std::endl << test3->name << std::endl;


	std::cout << BOLD ITAL ULINE BG_BRIGHT_BLACK "Serial 1:" RESET  "\n";
	std::cout << serial << std::endl;
	std::cout << BOLD ITAL ULINE BG_BRIGHT_BLACK "Serial 2:" RESET  "\n";
	std::cout << serial << std::endl;
	std::cout << &test1 << std::endl;
	std::cout << &test2 << std::endl;
	std::cout << &test3 << std::endl;

	delete test1;
}