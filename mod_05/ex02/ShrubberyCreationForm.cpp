/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:27:41 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/05/23 14:05:54 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):Form(target, 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& new_object):
Form(new_object.get_name(), 145, 137){
	*this = new_object;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void	ShrubberyCreationForm::execute(){
	std::string outfile = get_name() + "_shrubbery";
	std::ofstream	Outfile(outfile);
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
    }
    return(*this);
}