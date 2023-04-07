/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:29:41 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/07 11:09:46 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ClapTrap.hpp"
#include<iomanip>

int	main(void){
	ClapTrap	clap[4];
	std::string	input;
	int			clap_i = 0;
	int			clap_j = 0;
	int			dmgs = 0;
	int			repair;

	while(1){
		int	i = 0;
		while(i < 4){
		std::cout << "|Index:" << std::setw(10) << i
		<< "|Name:" << std::setw(10) << clap[i].get_name() 
		<< "|HP:" << std::setw(10) << clap[i].get_hit_point() 
		<< "|Energy:" << std::setw(10) <<clap[i].get_energy_point() << "|"
		<< "|DMG:" << std::setw(10) <<clap[i].get_attack_damage() << "|"
		<< std::endl;
		i++;}
	
		std::cout << "Create your own <claptrap>!, <attack> another claptrap, <repair> a claptrap or <exit>" << std::endl;
		getline(std::cin, input);
		if (std::cin.good()){
	
			if(input == "claptrap"){

				std::cout <<"Which one do you want to modify?: ";
				std::cin >> clap_i;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				if (clap_i >= 0 && clap_i <= 3){
					std::cout << "Name your claptrap: ";
					getline(std::cin, input);
	
					if (std::cin.good()){
							clap[clap_i].set_name(input);
							std::cout <<"Attack damages: ";
							std::cin >> dmgs;
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							clap[clap_i].set_attack_damage(dmgs);
						}
					else
						break ;	
				}
				else
					std::cout <<"choose an number between 0 & 3 next time"<<std::endl;
			}
			if(input == "attack"){
				std::cout <<"Who is the attacker?: ";
				std::cin >> clap_i;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout <<"Who is the target?: ";
				std::cin >> clap_j;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				if (std::cin.good()){
					if ((clap_i >= 0 && clap_i <= 3) && (clap_j >= 0 && clap_j <= 3)){
						clap[clap_i].attack(clap[clap_j].get_name());
						clap[clap_j].takeDamage(clap[clap_i].get_attack_damage());
					}
				}
				else
					break ;
			}
			if(input == "repair"){
				std::cout <<"Who is repairing?: ";
				std::cin >> clap_i;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout <<"For how many hp?: ";
				std::cin >> repair;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				if (std::cin.good()){
					if ((clap_i >= 0 && clap_i <= 3)){
						clap[clap_i].beRepaired(repair);
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