/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:11:17 by tristan           #+#    #+#             */
/*   Updated: 2023/05/23 18:38:37 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Bureaucrat.hpp"
#include"Form.hpp"
#include"Intern.hpp"
#include"ShrubberyCreationForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"PresidentialPardonForm.hpp"
#include <cstdlib>

void	print_tab(Bureaucrat& dude){
	std::cout<< BLUE_CL<< "|Name:" << PINK_CL  << std::setw(1) << dude << std::endl;
}

void	print_tab_form(Form* array){
	int i = 0;
	while (i < 10){
		std::cout<< BLUE_CL<< "|Name:" << PINK_CL  << std::setw(1) << array[i] << std::endl;
		i++;
	}
}

void	print_form_choice(){
	std::cout <<YELLOW_CL
	<<"<"<<PINK_CL <<"0 - 9"<<YELLOW_CL<<"> choose which form to sign or execute?"<<std::endl<<GREEN_CL;
}

void	print_choices(){
	std::cout<<YELLOW_CL<<"<"<< PINK_CL <<"up"<<YELLOW_CL <<"> grade up"<<std::endl<<
	"<"<<PINK_CL <<"down"<<YELLOW_CL<<"> grade down"<<std::endl <<
	"<"<<PINK_CL <<"exec"<<YELLOW_CL<<"> to execute a form"<<std::endl <<
	"<"<<PINK_CL <<"sign"<<YELLOW_CL<<"> to sign a form"<<std::endl;
}

int	str_convert(std::string& str){
	int i;
	try{
    	i = std::atoi(str.c_str());
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
	
    return i;
}

void	choices(Bureaucrat& dude, Form* array){
	std::string	input;
	getline(std::cin, input);
	
	if (input == "up")
		dude.grade_up();
	if (input == "down")
		dude.grade_down();
	if (input == "sign" || input == "exec"){
		int			i;
		print_form_choice();
		getline(std::cin, input);
		i = str_convert(input);
		
		if (i < 0 || i > 9){
			std::cout<<"Need to be between 0 and 9"<<std::endl;
			return ;
		}
		if (input == "sign")
			dude.signForm(array[i]);

		if (input == "exec"){
			dude.executeForm(array[i]);
		}
	}
}

void	form_creation(Intern intern, Form* array, int i){
	std::string	input;
	std::string	input2;
	std::cout<<YELLOW_CL<<"<"<< PINK_CL <<"shrubbery"<<YELLOW_CL <<">" 
	<<YELLOW_CL<<"<"<< PINK_CL <<"presidential"<<YELLOW_CL <<">"
	<<YELLOW_CL<<"<"<< PINK_CL <<"robotomy"<<YELLOW_CL <<"> what kind of form do you want to make?"<<std::endl<<GREEN_CL;
	getline(std::cin, input);
	std::cout<<YELLOW_CL<< "How do you want to call the form?" <<std::endl<<GREEN_CL; 
	getline(std::cin, input2);
	array[i] = *intern.makeForm(input, input2);
}

void	idgaf(Bureaucrat& bob, Bureaucrat& boris, Bureaucrat& karen, Bureaucrat& robert, Form* array){
	std::cout << "--------------------------" << std::endl;
	print_tab(bob);
	print_tab(boris);
	print_tab(karen);
	print_tab(robert);
	std::cout << "--------------------------" << std::endl;
	print_tab_form(array);
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
		Bureaucrat	bob("Bob", 1);	
		Bureaucrat	boris("Boris", 150);
		Bureaucrat	karen("Karen", 96 );
		Bureaucrat	robert("Robert", 100);
		Intern		intern;
		Form*		formArray[10];
		int			i = 0;
	
		while(1){
		
			if (std::cin.good()){
				idgaf(bob, boris, karen, robert, *formArray);
				getline(std::cin, input);

				if(input == "intern"){
					if (i < 10){
						form_creation(intern, *formArray, i);
						i++;
					}
					else
						std::cout<<"No more form can be created, cause I'm lazy."<<std::endl;
				}
				
				if (input == "bob"){
					choices(bob, *formArray);
				}
				if (input == "boris"){
					choices(boris, *formArray);
				}
				if (input == "karen"){
					choices(karen, *formArray);
				}
				if (input == "robert"){
					choices(robert, *formArray);
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
