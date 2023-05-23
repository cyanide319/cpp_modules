/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:59:30 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/05/23 19:10:45 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//DEFAULT CONSTRUCT
Intern::Intern(){
	_forms_name[0] = "Robotomy";
	_forms_name[1] = "Presidential";
	_forms_name[2] = "Shrubbery";
}

//COPY CONSTRUCT
Intern::Intern(Intern& new_object){*this = new_object;}

//DEFAULT DESTRUCT
Intern::~Intern(){}

Form*	Intern::makeForm(std::string name, std::string target){
	int i = 0;

	while (i < 3){
		if (_forms_name[i] == name){
			std::cout << "Intern creates " << name << std::endl;
			switch (i)
			{
			case 0:
				return (new RobotomyRequestForm(target));
			case 1:
				return (new PresidentialPardonForm(target));
			case 2:
				return (new ShrubberyCreationForm(target));
			}
		}
		i++;
	}
	std::cout << "Wrong form name. Try: Robotomy, Presidential or Shrubbery." << std::endl;
	return (NULL);
}
