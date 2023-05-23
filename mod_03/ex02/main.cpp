/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:29:41 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/05/23 18:29:02 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ClapTrap.hpp"
#include"ScavTrap.hpp"
#include"FragTrap.hpp"
#include<iomanip>

void	print_tab(ClapTrap& clap, ScavTrap *scav, FragTrap& frag){
	int	i = 0;
	std::cout<< BLUE_CL << "|Index:" << PINK_CL << std::setw(4) << i
	<< BLUE_CL << "|Name:" << PINK_CL << std::setw(10) << clap.get_name() 
	<<	BLUE_CL << "|HP:" << PINK_CL << std::setw(4) << clap.get_hit_point() 
	<<	BLUE_CL << "|Energy:" << PINK_CL << std::setw(4) << clap.get_energy_point()
	<<	BLUE_CL << "|DMG:" << PINK_CL << std::setw(4) << clap.get_attack_damage()
	<<	BLUE_CL << "|" << std::endl;
	i++;
	std::cout<< BLUE_CL << "|Index:" << PINK_CL << std::setw(4) << i
	<< BLUE_CL << "|Name:" << PINK_CL << std::setw(10) << frag.get_name() 
	<<	BLUE_CL << "|HP:" << PINK_CL << std::setw(4) << frag.get_hit_point() 
	<<	BLUE_CL << "|Energy:" << PINK_CL << std::setw(4) << frag.get_energy_point()
	<<	BLUE_CL << "|DMG:" << PINK_CL << std::setw(4) << frag.get_attack_damage()
	<<	BLUE_CL << "|" << std::endl;
	i++;
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
	ClapTrap	clap;
	FragTrap	frag;
	ScavTrap	scav[2];
	std::string	input;
	std::string clap_str;
	int			clap_i = 0;
	int			clap_j = 0;
	int			dmgs = 0;
	int			repair = 0;

	while(1){
	
		if (std::cin.good()){
			print_tab(clap, scav, frag);
			std::cout<<YELLOW_CL<<"<"<< PINK_CL <<"name"<<YELLOW_CL <<"> Create your own claptrap!"<<std::endl<<
			"<"<<PINK_CL << "attack"<<YELLOW_CL <<"> Attack another claptrap!"<<std::endl<<
			"<"<<PINK_CL <<"repair"<<YELLOW_CL<<"> Repair a claptrap!"<<std::endl<<
			"<"<<PINK_CL <<"guard"<<YELLOW_CL<<"> Your scavtrap enter guard mode!"<<std::endl<<
			"<"<<PINK_CL <<"high"<<YELLOW_CL<<"> ...High fives!"<<std::endl<<
			"<"<<PINK_CL <<"exit"<<YELLOW_CL<<">"<<std::endl<<GREEN_CL;
			getline(std::cin, input);
	
			if(input == "name"){
				std::cout<<YELLOW_CL<<"Which one do you want to modify?(Index): "<<GREEN_CL;
				getline(std::cin, clap_str);
				clap_i = str_convert(clap_str);
				switch(clap_i){
					case 0:
						std::cout<<YELLOW_CL<<"Name your ClapTrap: "<<GREEN_CL;
						getline(std::cin, input);
						input = format_str(input);
						clap.set_name(input);
						std::cout<<YELLOW_CL<<"Attack damages(Int): "<<GREEN_CL;
						getline(std::cin, clap_str);
						dmgs = str_convert(clap_str);
						if (dmgs >= 0 && dmgs <= 100) clap.set_attack_damage(dmgs);
						break ;
					case 1:
						std::cout<<YELLOW_CL<<"Name your FragTrap: "<<GREEN_CL;
						getline(std::cin, input);
						input = format_str(input);
						frag.set_name(input);
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
						std::cout<<YELLOW_CL<<"Who is the target?(Index): "<<GREEN_CL;
						getline(std::cin, clap_str);
						clap_j = str_convert(clap_str);
						switch(clap_j){
							case 0:
								clap.attack(clap.get_name());
								clap.takeDamage(clap.get_attack_damage());
								break ;
							case 1:
								clap.attack(frag.get_name());
								frag.takeDamage(clap.get_attack_damage());
								break ;
							case 2:
							case 3:
								clap.attack(scav[clap_j - 2].get_name());
								scav[clap_j - 2].takeDamage(clap.get_attack_damage());
								break ;
							}
						break ;
					case 1:
						std::cout<<YELLOW_CL<<"Who is the target?(Index): "<<GREEN_CL;
						getline(std::cin, clap_str);
						clap_j = str_convert(clap_str);
						switch(clap_j){
							case 0:
								frag.attack(clap.get_name());
								clap.takeDamage(frag.get_attack_damage());
								break ;
							case 1:
								frag.attack(frag.get_name());
								frag.takeDamage(frag.get_attack_damage());
								break ;
							case 2:
							case 3:
								frag.attack(scav[clap_j - 2].get_name());
								scav[clap_j - 2].takeDamage(frag.get_attack_damage());
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
								scav[clap_i - 2].attack(clap.get_name());
								clap.takeDamage(scav[clap_i - 2].get_attack_damage());
								break ;
							case 1:
								scav[clap_i - 2].attack(frag.get_name());
								frag.takeDamage(scav[clap_i - 2].get_attack_damage());
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
						std::cout<<YELLOW_CL<<"For how many hp?(Int): "<<GREEN_CL;
						getline(std::cin, clap_str);
						repair = str_convert(clap_str);
						if (repair >= 0)
							clap.beRepaired(repair);
						break ;
					case 1:
						std::cout<<YELLOW_CL<<"For how many hp?(Int): "<<GREEN_CL;
						getline(std::cin, clap_str);
						repair = str_convert(clap_str);
						if (repair >= 0)
							frag.beRepaired(repair);
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

			else if (input == "high"){
					frag.highFivesGuys();
					if (clap.get_hit_point() > 0)
						std::cout<<PINK_CL<<clap.get_name()<<" is giving "<<frag.get_name()<<" a high five!"<<std::endl;
					else
						std::cout<<RED_CL<<clap.get_name()<<" is dead!"<<std::endl;
					if (scav[0].get_hit_point() > 0)
						std::cout<<PINK_CL<<scav[0].get_name()<<" is giving "<<frag.get_name()<<" a high five!"<<std::endl;
					else
						std::cout<<RED_CL<<scav[0].get_name()<<" is dead!"<<std::endl;
					if (scav[1].get_hit_point() > 0)
						std::cout<<PINK_CL<<scav[1].get_name()<<" is giving "<<frag.get_name()<<" a high five!"<<std::endl;
					else
						std::cout<<RED_CL<<scav[1].get_name()<<" is dead!"<<std::endl;
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