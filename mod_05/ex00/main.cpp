/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:11:17 by tristan           #+#    #+#             */
/*   Updated: 2023/05/17 18:09:07 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Bureaucrat.hpp"

//void	print_tab(){
//	int	i = 0;
//	std::cout<< BLUE_CL << "|Index:" << PINK_CL << std::setw(4) << i
//	<< BLUE_CL << "|Name:" << PINK_CL << std::setw(15) << clap.get_name() 
//	<<	BLUE_CL << "|HP:" << PINK_CL << std::setw(4) << clap.get_hit_point() 
//	<<	BLUE_CL << "|Energy:" << PINK_CL << std::setw(4) << clap.get_energy_point()
//	<<	BLUE_CL << "|DMG:" << PINK_CL << std::setw(4) << clap.get_attack_damage()
//	<<	BLUE_CL << "|" << std::endl;
//	i++;
//}

//int	str_convert(std::string str){
//	int clap_i;
//	try {clap_i = std::stoi(str);}
//	catch (const std::exception& e) {std::cerr<< RED_CL <<"This input take an integer"<<std::endl; return (-1);}
//	return (clap_i);
	
//}

std::string	format_str(std::string str){
	if (str.size() > 9)
	{
		str.resize(9);
		str.append(".");
	}
	return (str);
}

int	main(void){
	std::string	input;
	try
	{
		Bureaucrat *bob = new Bureaucrat("Bob", 1);	
		Bureaucrat *boris = new Bureaucrat("Boris", 150);
		Bureaucrat *karen = new Bureaucrat("Karen", 96 );
		Bureaucrat *robert = new Bureaucrat("Robert", 100);

		bob->grade_up();
		bob->grade_down();
		boris->grade_down();
		boris->grade_up();
		karen->grade_down();
		karen->grade_up();
		robert->grade_down();
		robert->grade_up();

		std::cout << bob->get_grade() << std::endl;
		std::cout << boris->get_grade() << std::endl;
		std::cout << karen->get_grade() << std::endl;
		std::cout << robert->get_grade() << std::endl;
		
		Bureaucrat *fucker = new Bureaucrat("Robert", 10000);
		fucker->get_grade();
		delete bob;
		delete boris;
		delete karen;
		delete robert;
		delete fucker;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	
//	while(1){
	
//		if (std::cin.good()){
//			//print_tab(clap, scav, frag, diam);
//			std::cout<<YELLOW_CL<<"<"<< PINK_CL <<"name"<<YELLOW_CL <<"> Create your own claptrap!"<<std::endl<<
//			//"<"<<PINK_CL << "attack"<<YELLOW_CL <<"> Attack another claptrap!"<<std::endl<<
//			//"<"<<PINK_CL <<"repair"<<YELLOW_CL<<"> Repair a claptrap!"<<std::endl<<
//			//"<"<<PINK_CL <<"guard"<<YELLOW_CL<<"> Your scavtrap enter guard mode!"<<std::endl<<
//			//"<"<<PINK_CL <<"high"<<YELLOW_CL<<"> ...High fives!"<<std::endl<<
//			//"<"<<PINK_CL <<"who"<<YELLOW_CL<<"> ...Who are YOU?"<<std::endl<<
//			"<"<<PINK_CL <<"exit"<<YELLOW_CL<<">"<<std::endl<<GREEN_CL;
//			getline(std::cin, input);
			
//			if (input == "exit"){
//				std::cout<< PINK_CL <<"Goodbye Friend!"<<std::endl;
//				break ;
//			}
//		}
//		else
//			break ;
//	}
}