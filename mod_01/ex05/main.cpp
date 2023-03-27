/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:42:46 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/27 14:36:44 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void){
	Harl		harl;
	std::string	input;
	int			number;

	while(1){

		std::cout << "Choose a <DEBUG> message, an <INFO> message, a <WARNING> message, an <ERROR> message, or <EXIT>" << std::endl;
		getline(std::cin, input);
		if (std::cin.good()){
			if (input == "EXIT")
				break ;
			harl.complain(input);
		}
		else
			break ;
	}
}