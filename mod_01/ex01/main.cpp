/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:38:32 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/22 12:47:16 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Zombie.hpp"

int	main(void){
	std::string	input;
	int			number;

	while(1){

		std::cout << "Create a <zombie>, a <horde>, or <exit>" << std::endl;
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

			if(input == "horde"){
				std::cout << "Name your fucking horde: ";
				getline(std::cin, input);
				std::cout << "How much fucking horde: ";
				std::cin >> number;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				if (number > 40 || number < 0)
					std::cout << "Calm the fuck down dude" << std::endl;

				else if (std::cin.good()){
					Zombie* horde = zombieHorde(number, input);
					int	i = -1;
					if (number){
						while (i < (number - 1)){
							horde[++i].announce();
						}
						delete[] horde;
					}
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