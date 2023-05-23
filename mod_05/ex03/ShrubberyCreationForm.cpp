/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:27:41 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/05/23 19:00:34 by tristan          ###   ########.fr       */
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

void	ShrubberyCreationForm::execute(){
	std::string outfile = (get_target() + "_shrubbery");
	std::ofstream	Outfile(outfile.c_str());
	Outfile << "      /\\          /\\          /\\          /\\  " << std::endl
			<< "     /||\\        /||\\        /||\\        /||\\  " << std::endl
			<< "    /||||\\      /||||\\      /||||\\      /||||\\ " << std::endl
			<< "   /||||||\\    /||||||\\    /||||||\\    /||||||\\" << std::endl
			<< "  /||||||||\\  /||||||||\\  /||||||||\\  /||||||||\\" << std::endl
			<< "      ||          ||          ||          ||" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	if (this != &other){
        this->set_signed(other.get_signed());
		this->set_target(other.get_target());
    }
    return(*this);
}