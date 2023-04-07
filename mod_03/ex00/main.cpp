/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:29:41 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/07 13:50:24 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ClapTrap.hpp"
#include<iomanip>

void	print_tab(ClapTrap *clap){
	int	i = 0;
	while(i < 4){
		std::cout << BLUE_CL << "|Index:" << std::setw(10) << i
		<< "|Name:" << std::setw(10) << clap[i].get_name() 
		<< "|HP:" << std::setw(10) << clap[i].get_hit_point() 
		<< "|Energy:" << std::setw(10) <<clap[i].get_energy_point() << "|"
		<< "|DMG:" << std::setw(10) <<clap[i].get_attack_damage() << "|"
		<< std::endl;
		i++;}
}

int	str_convert(std::string str){
	int clap_i;
	try {clap_i = std::stoi(str);}
	catch (const std::exception& e) {std::cerr<< RED_CL <<"This input take an integer"<<std::endl; return (-1);}
	return (clap_i);
	
}

int	main(void){
	ClapTrap	clap[4];
	std::string	input;
	std::string clap_str;
	int			clap_i = 0;
	int			clap_j = 0;
	int			dmgs = 0;
	int			repair = 0;

	while(1){
	
		if (std::cin.good()){
			print_tab(clap);
			std::cout<< YELLOW_CL << "Create your own <claptrap>!, <attack> another claptrap, <repair> a claptrap or <exit>" << std::endl;
			getline(std::cin, input);
	
			if(input == "claptrap"){

				std::cout<< YELLOW_CL <<"Which one do you want to modify?(Index): ";
				getline(std::cin, clap_str);
				clap_i = str_convert(clap_str);
				if (clap_i >= 0 && clap_i <= 3){
					std::cout<< YELLOW_CL << "Name your claptrap: ";
					getline(std::cin, input);
					clap[clap_i].set_name(input);
					std::cout<< YELLOW_CL <<"Attack damages(Int): ";
					getline(std::cin, clap_str);
					dmgs = str_convert(clap_str);
					if (dmgs >= 0)
						clap[clap_i].set_attack_damage(dmgs);					
				}
			}

			else if(input == "attack"){
				std::cout<< YELLOW_CL <<"Who is the attacker?(Index): ";
				getline(std::cin, clap_str);
				clap_i = str_convert(clap_str);
				if (clap_i >= 0 && clap_i <= 3){
					std::cout<< YELLOW_CL <<"Who is the target?(Index): ";
					getline(std::cin, clap_str);
					clap_j = str_convert(clap_str);
						if ((clap_j >= 0 && clap_j <= 3)){
							clap[clap_i].attack(clap[clap_j].get_name());
							clap[clap_j].takeDamage(clap[clap_i].get_attack_damage());
						}
				}
			}

			else if(input == "repair"){
				std::cout<< YELLOW_CL <<"Who is repairing?(Index): ";
				getline(std::cin, clap_str);
				clap_i = str_convert(clap_str);
				if (clap_i >= 0 && clap_i <= 3){
					std::cout<< YELLOW_CL <<"For how many hp?(Int): ";
					getline(std::cin, clap_str);
					repair = str_convert(clap_str);
					if (repair >= 0)
						clap[clap_i].beRepaired(repair);
				}
			}

			else if (input == "exit"){
				std::cout<< PINK_CL <<"Goodbye Friend!"<<std::endl;
				break ;
			}
		}
		else
			break ;
	}
}