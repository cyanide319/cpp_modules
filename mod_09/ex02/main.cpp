/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:07:29 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/08/17 11:56:31 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		std::cerr << "Error: Need one argument" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe test(argv[1]);
		test.print_vector();
		test.print_list();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}