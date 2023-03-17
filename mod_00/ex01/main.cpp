/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:53:06 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/17 14:47:43 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PhoneBook.hpp"

int main(void){
	PhoneBook PhoneBook; 
	std::string	input;
	
	while (1){
		std::cout << "Enter ADD, SEARCH or EXIT" << std::endl;
		getline(std::cin, input);
		if (std::cin.good()){
			if (input == "ADD")
			{
				if (PhoneBook.add_contact() < 0)
					std::cout << "All field must be filled with at least one character" << std::endl;
			}
			else if (input == "SEARCH")
				PhoneBook.search_contact();
			else if (input == "EXIT")
				break ;
		}
		else
			break ;
	}
	return (0);
}