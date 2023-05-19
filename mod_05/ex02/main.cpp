/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:11:17 by tristan           #+#    #+#             */
/*   Updated: 2023/05/19 16:44:48 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Bureaucrat.hpp"
#include"Form.hpp"
#include"ShrubberyCreationForm.hpp"

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
	"<"<<PINK_CL <<"3"<<YELLOW_CL<<">"
	 << "> to sign a form"<<std::endl<<GREEN_CL;
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
	return (0);
}

void	executing(Bureaucrat& dude, Form& un, Form& deux, Form& trois, int ret){
	switch (ret)
	{
	case 0:
		break;
	case 1:
		un.execute(dude);
		break;
	case 2:
		deux.execute(dude);
		break;
	case 3:
		trois.execute(dude);
		break;
	}
}

void	signing(Bureaucrat& dude, Form& un, Form& deux, Form& trois, int ret){
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
	int			ret;
	try
	{
		Bureaucrat bob("Bob", 1);	
		Bureaucrat boris("Boris", 150);
		Bureaucrat karen("Karen", 96 );
		Bureaucrat robert("Robert", 100);
		ShrubberyCreationForm un("prime");
		ShrubberyCreationForm deux("anticonstitutionnellement");
		ShrubberyCreationForm trois("fuck");
		
		// Bureaucrat *fucker = new Bureaucrat("Robert", 10000);
	
		while(1){
		
			if (std::cin.good()){
				idgaf(bob, boris, karen, robert, un, deux, trois);
				getline(std::cin, input);
				
				if (input == "bob"){
					print_choices();
					ret = choices(bob);
					if (ret != 0)
						signing(bob, un, deux, trois, ret);
				}
				if (input == "boris"){
					print_choices();
					ret = choices(boris);
					if (ret != 0)
						signing(boris, un, deux, trois, ret);
				}
				if (input == "karen"){
					print_choices();
					ret = choices(karen);
					if (ret != 0)
						signing(karen, un, deux, trois, ret);
				}
				if (input == "robert"){
					print_choices();
					ret = choices(robert);
					if (ret != 0)
						signing(robert, un, deux, trois, ret);
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
