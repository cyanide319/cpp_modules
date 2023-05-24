/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:27:41 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/05/24 17:51:27 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ShrubberyCreationForm.hpp"

//DEFAULT CONSTRUCT
ShrubberyCreationForm::ShrubberyCreationForm():
Form("Shrubbery Creation", 145, 137){set_target("default");}

//NAMED CONSTRUCT
ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
Form("Shrubbery Creation", 145, 137){set_target(target);}

//COPY CONSTRUCT
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& new_object):
Form(new_object.get_name(), 145, 137){
	*this = new_object;
}

//DEFAULT DESTRUCT
ShrubberyCreationForm::~ShrubberyCreationForm(){}

int	ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const{
	if (bureaucrat.get_grade() <= this->get_to_sign()){
		if (get_signed() == true){
		std::string outfile = (get_target() + "_shrubbery");
		std::ofstream	Outfile(outfile.c_str());
		Outfile << "      /\\          /\\          /\\          /\\  " << std::endl
				<< "     /||\\        /||\\        /||\\        /||\\  " << std::endl
				<< "    /||||\\      /||||\\      /||||\\      /||||\\ " << std::endl
				<< "   /||||||\\    /||||||\\    /||||||\\    /||||||\\" << std::endl
				<< "  /||||||||\\  /||||||||\\  /||||||||\\  /||||||||\\" << std::endl
				<< "      ||          ||          ||          ||" << std::endl;
			return (0);
		}
		else{
			return(2);
		}
	}
	throw Form::GradeTooLowException();
	return (1);
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	if (this != &other){
        this->set_signed(other.get_signed());
		this->set_target(other.get_target());
    }
    return(*this);
}