/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:29:41 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/11 18:00:58 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ClapTrap.hpp"
#include"ScavTrap.hpp"
#include<iomanip>

void	print_tab(ClapTrap *clap, ScavTrap *scav){
	int	i = 0;
	while(i < 2){
		std::cout<< BLUE_CL << "|Index:" << PINK_CL << std::setw(4) << i
		<< BLUE_CL << "|Name:" << PINK_CL << std::setw(10) << clap[i].get_name() 
		<<	BLUE_CL << "|HP:" << PINK_CL << std::setw(4) << clap[i].get_hit_point() 
		<<	BLUE_CL << "|Energy:" << PINK_CL << std::setw(4) << clap[i].get_energy_point()
		<<	BLUE_CL << "|DMG:" << PINK_CL << std::setw(4) << clap[i].get_attack_damage()
		<<	BLUE_CL << "|" << std::endl;
		i++;}
	while(i < 4){
		std::cout<< BLUE_CL << "|Index:" << PINK_CL << std::setw(4) << i
		<<	BLUE_CL << "|Name:"<< PINK_CL << std::setw(10) << scav[i - 2].get_name() 
		<<	BLUE_CL << "|HP:"<< PINK_CL << std::setw(4) << scav[i - 2].get_hit_point() 
		<<	BLUE_CL << "|Energy:"<< PINK_CL << std::setw(4) << scav[i - 2].get_energy_point()
		<<	BLUE_CL << "|DMG:"<< PINK_CL << std::setw(4) << scav[i - 2].get_attack_damage()
		<<	BLUE_CL << "|Guard:"<< PINK_CL << std::setw(4) << scav[i - 2].get_guard_mode()
		<<	BLUE_CL << "|"<< std::endl;
		i++;}
}

int	str_convert(std::string str){
	int clap_i;
	try {clap_i = std::stoi(str);}
	catch (const std::exception& e) {std::cerr<< RED_CL <<"This input take an integer"<<std::endl; return (-1);}
	return (clap_i);
	
}

std::string	format_str(std::string str){
	if (str.size() > 9)
	{
		str.resize(9);
		str.append(".");
	}
	return (str);
}

int	main(void){
	ClapTrap	clap[2];
	ScavTrap	scav[2];
	std::string	input;
	std::string clap_str;
	int			clap_i = 0;
	int			clap_j = 0;
	int			dmgs = 0;
	int			repair = 0;

	while(1){
	
		if (std::cin.good()){
			print_tab(clap, scav);
			std::cout<<YELLOW_CL<<"<"<< PINK_CL <<"name"<<YELLOW_CL <<"> Create your own claptrap!"<<std::endl<<
			"<"<<PINK_CL << "attack"<<YELLOW_CL <<"> Attack another claptrap!"<<std::endl<<
			"<"<<PINK_CL <<"repair"<<YELLOW_CL<<"> Repair a claptrap!"<<std::endl<<
			"<"<<PINK_CL <<"guard"<<YELLOW_CL<<"> Your scavtrap enter guard mode!"<<std::endl<<
			"<"<<PINK_CL <<"exit"<<YELLOW_CL<<">"<<std::endl<<GREEN_CL;
			getline(std::cin, input);
	
			if(input == "name"){
				std::cout<<YELLOW_CL<<"Which one do you want to modify?(Index): "<<GREEN_CL;
				getline(std::cin, clap_str);
				clap_i = str_convert(clap_str);
				switch(clap_i){
					case 0:
					case 1:
						std::cout<<YELLOW_CL<<"Name your ClapTrap: "<<GREEN_CL;
						getline(std::cin, input);
						input = format_str(input);
						clap[clap_i].set_name(input);
						std::cout<<YELLOW_CL<<"Attack damages(Int): "<<GREEN_CL;
						getline(std::cin, clap_str);
						dmgs = str_convert(clap_str);
						if (dmgs >= 0 && dmgs <= 100) clap[clap_i].set_attack_damage(dmgs);
						break ;
					case 2:
					case 3:
						std::cout<<YELLOW_CL<<"Name your ScavTrap: "<<GREEN_CL;
						getline(std::cin, input);
						input = format_str(input);
						scav[clap_i - 2].set_name(input);
						break ;
				}
			}			

			else if(input == "attack"){
				std::cout<<YELLOW_CL<<"Who is the attacker?(Index): "<<GREEN_CL;
				getline(std::cin, clap_str);
				clap_i = str_convert(clap_str);
				switch(clap_i){
					case 0:
					case 1:
						std::cout<<YELLOW_CL<<"Who is the target?(Index): "<<GREEN_CL;
						getline(std::cin, clap_str);
						clap_j = str_convert(clap_str);
						switch(clap_j){
							case 0:
							case 1:
								clap[clap_i].attack(clap[clap_j].get_name());
								clap[clap_j].takeDamage(clap[clap_i].get_attack_damage());
								break ;
							case 2:
							case 3:
								clap[clap_i].attack(scav[clap_j - 2].get_name());
								scav[clap_j - 2].takeDamage(clap[clap_i].get_attack_damage());
								break ;
							}
						break ;

					case 2:
					case 3:
						std::cout<<YELLOW_CL<<"Who is the target?(Index): "<<GREEN_CL;
						getline(std::cin, clap_str);
						clap_j = str_convert(clap_str);
						switch(clap_j){
							case 0:
							case 1:
								scav[clap_i - 2].attack(clap[clap_j].get_name());
								clap[clap_j].takeDamage(scav[clap_i - 2].get_attack_damage());
								break ;
							case 2:
							case 3:
								scav[clap_i - 2].attack(scav[clap_j - 2].get_name());
								scav[clap_j - 2].takeDamage(scav[clap_i - 2].get_attack_damage());
								break ;
							}
						break ;
				}
			}

			else if(input == "repair"){
				std::cout<<YELLOW_CL<<"Who is repairing?(Index): "<<GREEN_CL;
				getline(std::cin, clap_str);
				clap_i = str_convert(clap_str);
				switch (clap_i){
					case 0:
					case 1:
						std::cout<<YELLOW_CL<<"For how many hp?(Int): "<<GREEN_CL;
						getline(std::cin, clap_str);
						repair = str_convert(clap_str);
						if (repair >= 0)
							clap[clap_i].beRepaired(repair);
						break ;
					case 2:
					case 3:
						std::cout<<YELLOW_CL<<"For how many hp?(Int): "<<GREEN_CL;
						getline(std::cin, clap_str);
						repair = str_convert(clap_str);
						if (repair >= 0)
							scav[clap_i - 2].beRepaired(repair);
						break ;
				}
			}
			
			else if (input == "guard"){
				std::cout<<YELLOW_CL<<"Who is guarding?(Index (2 or 3)): "<<GREEN_CL;
				getline(std::cin, clap_str);
				clap_i = str_convert(clap_str);
				switch (clap_i){
					case 2:
					case 3:
						scav[clap_i - 2].guardGate();
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