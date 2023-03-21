/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:38:32 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/21 15:47:28 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Zombie.hpp"

int	main(void){
	std::string	input;

	while(1){
		std::cout << "Create a <zombie>, a <random> chump, or <exit>" << std::endl;
		getline(std::cin, input);
		if (std::cin.good()){
			if(input == "zombie"){
				std::cout << "Name your zombie: ";
				getline(std::cin, input);
				if (std::cin.good()){
					Zombie	*newZ = newZombie(input);
					std::cout << "Die " << input << "!!" << std::endl;
					delete newZ;
				}
				else
					break ;
			}
			if(input == "random"){
				std::cout << "Name your random chump: ";
				getline(std::cin, input);
				if (std::cin.good()){
					randomChump(input);
				}
				else
					break ;
			}
			else if (input == "exit")
				break ;
		}
		else
			break ;
	}
}