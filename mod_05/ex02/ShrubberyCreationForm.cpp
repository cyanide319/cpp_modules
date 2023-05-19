/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:27:41 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/05/19 17:14:12 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):Form(target, 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& new_object): Form(new_object.get_name(), 145, 137){
	*this = new_object;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void	ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat){
	if (bureaucrat.get_grade() <= this->get_to_exec()){
		if (this->get_signed() == true){
			std::string outfile = get_name() + "_shrubbery";
			std::ofstream	Outfile(outfile);
			std::cout << bureaucrat.get_name() << " executed " << this->get_name() << std::endl;
			Outfile << "      /\\          /\\          /\\          /\\  " << std::endl
					<< "     /||\\        /||\\        /||\\        /||\\  " << std::endl
					<< "    /||||\\      /||||\\      /||||\\      /||||\\ " << std::endl
					<< "   /||||||\\    /||||||\\    /||||||\\    /||||||\\" << std::endl
					<< "  /||||||||\\  /||||||||\\  /||||||||\\  /||||||||\\" << std::endl
					<< "      ||          ||          ||          ||" << std::endl;
		}
		else
			std::cout << "The form " << get_name() << " need to be signed before it can be executed!" << std::endl;
	}
	else
		throw Form::GradeTooLowException();
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	if (this != &other){
        this->set_signed(other.get_signed());
    }
    return(*this);
}