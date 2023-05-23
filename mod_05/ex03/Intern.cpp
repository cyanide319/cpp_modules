/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:59:30 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/05/23 17:37:09 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//DEFAULT CONSTRUCT
Intern::Intern():_forms_name({"Robotomy", "Presidential", "Shrubbery"}){}

//COPY CONSTRUCT
Intern::Intern(Intern& new_object){*this = new_object;}

//DEFAULT DESTRUCT
Intern::~Intern(){}

Form*	Intern::makeForm(std::string name, std::string target){
	int i = 0;
	Form* new_form;

	while (i < 3){
		if (_forms_name[i] == name){
			std::cout << "Intern creates " << name << std::endl;
			switch (i)
			{
			case 0:
				*new_form = RobotomyRequestForm(target);
				return (new_form);
			case 1:
				*new_form = PresidentialPardonForm(target);
				return (new_form);
			case 2:
				*new_form = ShrubberyCreationForm(target);
				return (new_form);
			}
		}
		i++;
	}
	std::cout << "Wrong form name. Try: Robotomy, Presidential or Shrubbery." << std::endl;
	return ;
}
