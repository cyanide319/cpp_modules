/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:11:17 by tristan           #+#    #+#             */
/*   Updated: 2023/05/23 14:13:16 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<cstdlib>
#include"Bureaucrat.hpp"
#include"Form.hpp"
#include"ShrubberyCreationForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"PresidentialPardonForm.hpp"

void	print_tab(Bureaucrat& dude){
	std::cout<< BLUE_CL<< "|Name:" << PINK_CL  << std::setw(1) << dude << std::endl;
}

void	print_tab_form(Form& form){
	std::cout<< BLUE_CL<< "|Name:" << PINK_CL  << std::setw(1) << form << std::endl;
}

void	print_form_choice(){
	std::cout <<YELLOW_CL"<"<<PINK_CL <<"1"<<YELLOW_CL
	<<"> for the shrubbery creation form" << std::endl
	<<"<"<<PINK_CL <<"2"<<YELLOW_CL<<"> for the robotomy request" << std::endl
	<<"<"<<PINK_CL <<"3"<<YELLOW_CL<<"> for the presidential pardon"<<std::endl<<GREEN_CL;
}

void	print_choices(){
	std::cout<<YELLOW_CL<<"<"<< PINK_CL <<"up"<<YELLOW_CL <<"> grade up"<<std::endl<<
	"<"<<PINK_CL <<"down"<<YELLOW_CL<<"> grade down"<<std::endl <<
	"<"<<PINK_CL <<"exec"<<YELLOW_CL<<"> to execute a form"<<std::endl <<
	"<"<<PINK_CL <<"sign"<<YELLOW_CL<<"> to sign a form"<<std::endl;
}

void	choices(Bureaucrat& dude, Form& un, Form& deux, Form& trois){
	std::string	input;
	getline(std::cin, input);
	
	if (input == "up")
		dude.grade_up();
	if (input == "down")
		dude.grade_down();
	if (input == "sign"){
		print_form_choice();
		getline(std::cin, input);
		if (input == "1")
			dude.signForm(un);
		if (input == "2")
			dude.signForm(deux);
		if (input == "3")
			dude.signForm(trois);
	}
	if (input == "exec"){
		print_form_choice();
		getline(std::cin, input);
		if (input == "1")
			dude.executeForm(un);
		if (input == "2")
			dude.executeForm(deux);
		if (input == "3")
			dude.executeForm(trois);
	}
}

void	idgaf(Bureaucrat& bob, Bureaucrat& boris, Bureaucrat& karen, Bureaucrat& robert, Form& un, Form& deux, Form& trois){
	std::cout << "--------------------------" << std::endl;
	print_tab(bob);
	print_tab(boris);
	print_tab(karen);
	print_tab(robert);
	std::cout << "--------------------------" << std::endl;
	print_tab_form(un);
	print_tab_form(deux);
	print_tab_form(trois);
	std::cout << "--------------------------" << std::endl;
	std::cout<<YELLOW_CL<<"<"<< PINK_CL <<"bob"<<YELLOW_CL <<">" 
	<<YELLOW_CL<<"<"<< PINK_CL <<"boris"<<YELLOW_CL <<">"
	<<YELLOW_CL<<"<"<< PINK_CL <<"karen"<<YELLOW_CL <<">"
	<<YELLOW_CL<<"<"<< PINK_CL <<"robert"<<YELLOW_CL <<"> which one you want to change?"
	<<std::endl<<"<"<<PINK_CL <<"exit"<<YELLOW_CL<<">"<<std::endl<<GREEN_CL;	
}

int	main(void){
	std::string	input;
	try
	{
		const char* userVar = std::getenv("USER");
		std::string	var;
		if (userVar != nullptr)
			var = userVar;
		else
			var = "Whatever";
		Bureaucrat bob("Bob", 1);	
		Bureaucrat boris("Boris", 150);
		Bureaucrat karen("Karen", 96 );
		Bureaucrat robert("Robert", 100);
		ShrubberyCreationForm un("the outdoor sucks");
		RobotomyRequestForm deux("Manon");
		PresidentialPardonForm trois(var);
	
		while(1){
		
			if (std::cin.good()){
				idgaf(bob, boris, karen, robert, un, deux, trois);
				getline(std::cin, input);
				
				if (input == "bob"){
					print_choices();
					choices(bob, un, deux, trois);
				}
				if (input == "boris"){
					print_choices();
					choices(boris, un, deux, trois);
				}
				if (input == "karen"){
					print_choices();
					choices(karen, un, deux, trois);
				}
				if (input == "robert"){
					print_choices();
					choices(robert, un, deux, trois);
				}
				if (input == "exit"){
					std::cout<< PINK_CL <<"Goodbye Friend!"<<std::endl;
					break ;
				}
			}
			else
				break ;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
