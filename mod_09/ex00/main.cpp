/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:13:13 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/07/12 12:27:36 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv){
	if (argc < 2){
		std::cerr << "Error: no argument" << std::endl;
		return (1);
	}
	std::ifstream infile(argv[1]);
	if (!infile){
		std::cerr << "Error: no file" << std::endl;
		return (1);
	}
	try{
		BitcoinExchange test(argv[1]);
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
}