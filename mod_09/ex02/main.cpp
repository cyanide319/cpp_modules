/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:07:29 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/08/23 11:56:28 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv){
	if (argc < 2){
		std::cerr << "Error: Need one argument" << std::endl;
		return (1);
	}
	try
	{
		if (argc == 2){
			PmergeMe test(argv[1]);
			test.is_sorted();	
		}
		else{
			std::string input;
			for (int i = 1; i < argc; i++){
				input += argv[i];
				input += " ";
			}
			PmergeMe test(input);
			test.is_sorted();	
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}