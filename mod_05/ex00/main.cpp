/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:11:17 by tristan           #+#    #+#             */
/*   Updated: 2023/05/23 13:13:20 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Bureaucrat.hpp"

void	print_tab(Bureaucrat& dude){
	std::cout<< BLUE_CL<< "|Name:" << PINK_CL  << std::setw(1) << dude << std::endl;
}

int	main(void){
	std::string	input;
	try
	{
		Bureaucrat *bob = new Bureaucrat("Bob", 1);	
		Bureaucrat *boris = new Bureaucrat("Boris", 150);
		Bureaucrat *karen = new Bureaucrat("Karen", 96 );
		Bureaucrat *robert = new Bureaucrat("Robert", 100);
	
		while(1){
		
			if (std::cin.good()){
				print_tab(*bob);
				print_tab(*boris);
				print_tab(*karen);
				print_tab(*robert);
				std::cout<<YELLOW_CL<<"<"<< PINK_CL <<"Bob"<<YELLOW_CL <<">" 
				<<YELLOW_CL<<"<"<< PINK_CL <<"Boris"<<YELLOW_CL <<">"
				<<YELLOW_CL<<"<"<< PINK_CL <<"Karen"<<YELLOW_CL <<">"
				<<YELLOW_CL<<"<"<< PINK_CL <<"Robert"<<YELLOW_CL <<"> which one you want to change?"
				<<std::endl<<"<"<<PINK_CL <<"exit"<<YELLOW_CL<<">"<<std::endl<<GREEN_CL;
				getline(std::cin, input);
				
				if (input == "Bob"){
					std::cout<<YELLOW_CL<<"<"<< PINK_CL <<"up"<<YELLOW_CL <<"> grade up"<<std::endl<<
					"<"<<PINK_CL <<"down"<<YELLOW_CL<<"> grade down"<<std::endl<<GREEN_CL;
					getline(std::cin, input);
					
					if (input == "up")
						bob->grade_up();
					if (input == "down")
						bob->grade_down();
				}
				if (input == "Boris"){
					std::cout<<YELLOW_CL<<"<"<< PINK_CL <<"up"<<YELLOW_CL <<"> grade up"<<std::endl<<
					"<"<<PINK_CL <<"down"<<YELLOW_CL<<"> grade down"<<std::endl<<GREEN_CL;
					getline(std::cin, input);
					
					if (input == "up")
						boris->grade_up();
					if (input == "down")
						boris->grade_down();
				}
				if (input == "Karen"){
					std::cout<<YELLOW_CL<<"<"<< PINK_CL <<"up"<<YELLOW_CL <<"> grade up"<<std::endl<<
					"<"<<PINK_CL <<"down"<<YELLOW_CL<<"> grade down"<<std::endl<<GREEN_CL;
					getline(std::cin, input);
					
					if (input == "up")
						karen->grade_up();
					if (input == "down")
						karen->grade_down();
				}
				if (input == "Robert"){
					std::cout<<YELLOW_CL<<"<"<< PINK_CL <<"up"<<YELLOW_CL <<"> grade up"<<std::endl<<
					"<"<<PINK_CL <<"down"<<YELLOW_CL<<"> grade down"<<std::endl<<GREEN_CL;
					getline(std::cin, input);
					
					if (input == "up")
						robert->grade_up();
					if (input == "down")
						robert->grade_down();
				}
				
				if (input == "exit"){
					std::cout<< PINK_CL <<"Goodbye Friend!"<<std::endl;
					break ;
				}
			}
			else
				break ;
		}
		delete bob;
		delete boris;
		delete karen;
		delete robert;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

// int	main(void){
// 	std::string	input;
// 	try
// 	{
// 		Bureaucrat *bob = new Bureaucrat("Bob", 1);	
// 		Bureaucrat *boris = new Bureaucrat("Boris", 150);
// 		Bureaucrat *karen = new Bureaucrat("Karen", 96 );
// 		Bureaucrat *robert = new Bureaucrat("Robert", 100);

// 		bob->grade_up();
// 		bob->grade_down();
// 		boris->grade_down();
// 		boris->grade_up();
// 		karen->grade_down();
// 		karen->grade_up();
// 		robert->grade_down();
// 		robert->grade_up();

// 		std::cout << bob->get_grade() << std::endl;
// 		std::cout << boris->get_grade() << std::endl;
// 		std::cout << karen->get_grade() << std::endl;
// 		std::cout << robert->get_grade() << std::endl;
		
// 		Bureaucrat *fucker = new Bureaucrat("Robert", 10000);
// 		fucker->get_grade();
// 		delete bob;
// 		delete boris;
// 		delete karen;
// 		delete robert;
// 		delete fucker;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// }