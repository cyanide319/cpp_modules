/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:07:12 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/06/14 14:04:37 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "color.h"

int main(){
	std::cout << BOLD ITAL BG_CYAN "empty test" RESET<< std::endl;

	Array <int>whatever;
	try{
		std::cout << PINK "whatever size " << whatever.size() << std::endl;
		std::cout << whatever[0] << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}

	std::cout << BOLD ITAL BG_CYAN "int test" RESET<< std::endl;

	Array <int>whatever2(5);
	try{
		whatever2[0] = 69;
		whatever2[1] = 96;
		whatever2[2] = 6969;
		whatever2[3] = 9696;
		whatever2[4] = 6996;
		std::cout << PINK "whatever2  case 4: "<< whatever2[4] << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}

	std::cout << BOLD ITAL BG_CYAN "string test" RESET << std::endl;

	Array <std::string>whatever3(5);
	try{
		whatever3[0] = "69";
		whatever3[1] = "96";
		whatever3[2] = "6969";
		whatever3[3] = "9696";
		whatever3[4] = "6996";
		std::cout << PINK "whatever3  case 4: " << whatever3[4] << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}

	std::cout << BOLD ITAL BG_CYAN "Copy assigment test" RESET << std::endl;

	Array <int>test(whatever2);
	try{
		std::cout << PINK "test case 4: " << test[4] << std::endl;
		test[4] = 69;
		std::cout << "test case 4: "<< test[4] << std::endl;
		std::cout << "whatever2 case 4: "<< whatever2[4] << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
}