/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:11:17 by tristan           #+#    #+#             */
/*   Updated: 2023/05/18 16:04:59 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Bureaucrat.hpp"
#include"Form.hpp"

std::string	format_str(std::string str){
	if (str.size() > 9)
	{
		str.resize(9);
		str.append(".");
	}
	return (str);
}

void	print_tab(Bureaucrat& dude){
	std::cout<< BLUE_CL<< "|Name:" << PINK_CL  << std::setw(1) << dude << std::endl;
}

void	print_tab_form(Form& form){
	std::cout<< BLUE_CL<< "|Name:" << PINK_CL  << std::setw(1) << form << std::endl;
}


void	print_choices(){
	std::cout<<YELLOW_CL<<"<"<< PINK_CL <<"up"<<YELLOW_CL <<"> grade up"<<std::endl<<
	"<"<<PINK_CL <<"down"<<YELLOW_CL<<"> grade down"<<std::endl<<YELLOW_CL
	"<"<<PINK_CL <<"1"<<YELLOW_CL<<">" "<"<<PINK_CL <<"2"<<YELLOW_CL<<">"
	"<"<<PINK_CL <<"3"<<YELLOW_CL<<">" "<"<<PINK_CL <<"4"<<YELLOW_CL<<">"
	 << "> to sign a form"<<std::endl<<WHITE_CL;
}

int	choices(Bureaucrat& dude){
	std::string	input;
	getline(std::cin, input);
	
	if (input == "up")
		dude.grade_up();
	if (input == "down")
		dude.grade_down();
	if (input == "1")
		return (1);
	if (input == "2")
		return (2);
	if (input == "3")
		return (3);
	if (input == "4")
		return (4);
	return (0);
}

void	signing(Bureaucrat& dude, Form& un, Form& deux, Form& trois, Form& quatre, int ret){
	switch (ret)
	{
	case 0:
		break;
	case 1:
		dude.signForm(un);
		break;
	case 2:
		dude.signForm(deux);
		break;
	case 3:
		dude.signForm(trois);
		break;
	case 4:
		dude.signForm(quatre);
		break;
	}
}

void	idgaf(Bureaucrat& bob, Bureaucrat& boris, Bureaucrat& karen, Bureaucrat& robert, Form& un, Form& deux, Form& trois, Form& quatre){
	std::cout << "--------------------------" << std::endl;
	print_tab(bob);
	print_tab(boris);
	print_tab(karen);
	print_tab(robert);
	std::cout << "--------------------------" << std::endl;
	print_tab_form(un);
	print_tab_form(deux);
	print_tab_form(trois);
	print_tab_form(quatre);
	std::cout << "--------------------------" << std::endl;
	std::cout<<YELLOW_CL<<"<"<< PINK_CL <<"Bob"<<YELLOW_CL <<">" 
	<<YELLOW_CL<<"<"<< PINK_CL <<"Boris"<<YELLOW_CL <<">"
	<<YELLOW_CL<<"<"<< PINK_CL <<"Karen"<<YELLOW_CL <<">"
	<<YELLOW_CL<<"<"<< PINK_CL <<"Robert"<<YELLOW_CL <<"> which one you want to change?"
	<<std::endl<<"<"<<PINK_CL <<"exit"<<YELLOW_CL<<">"<<std::endl<<GREEN_CL;	
}
//int	str_convert(std::string str){
//	int clap_i;
//	try {clap_i = std::stoi(str);}
//	catch (const std::exception& e) {std::cerr<< RED_CL <<"This input take an integer"<<std::endl; return (-1);}
//	return (clap_i);
	
//}

int	main(void){
	std::string	input;
	int			ret;
	try
	{
		Bureaucrat *bob = new Bureaucrat("Bob", 1);	
		Bureaucrat *boris = new Bureaucrat("Boris", 150);
		Bureaucrat *karen = new Bureaucrat("Karen", 96 );
		Bureaucrat *robert = new Bureaucrat("Robert", 100);
		Form un("prime", 1, 150);
		Form deux("secundo", 100, 150);
		Form trois("fuck", 150, 150);
		Form quatre("anticonstitutionnellement", 69, 150);
		
		// Bureaucrat *fucker = new Bureaucrat("Robert", 10000);
	
		while(1){
		
			if (std::cin.good()){
				idgaf(*bob, *boris, *karen, *robert, un, deux, trois, quatre);
				getline(std::cin, input);
				
				if (input == "Bob"){
					print_choices();
					ret = choices(*bob);
					if (ret != 0)
						signing(*bob, un, deux, trois, quatre, ret);
				}
				if (input == "Boris"){
					print_choices();
					ret = choices(*boris);
					if (ret != 0)
						signing(*boris, un, deux, trois, quatre, ret);
				}
				if (input == "Karen"){
					print_choices();
					ret = choices(*karen);
					if (ret != 0)
						signing(*karen, un, deux, trois, quatre, ret);
				}
				if (input == "Robert"){
					print_choices();
					ret = choices(*robert);
					if (ret != 0)
						signing(*robert, un, deux, trois, quatre, ret);
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
		// delete fucker;
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