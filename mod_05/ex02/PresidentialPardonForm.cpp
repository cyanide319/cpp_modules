/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:27:57 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/05/23 14:23:52 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target):
Form("Presidential Pardon", 25, 5){set_target(target);}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& new_object):
Form(new_object.get_name(), 25, 5){
	*this = new_object;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void	PresidentialPardonForm::execute(){
	std::cout << "By the surpreme autority of the God Emperor Zaphod Beeblebrox, you, "
		<< get_target() <<  ", have been pardonned. Now proceed with the execution." << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	if (this != &other){
        this->set_signed(other.get_signed());
		this->set_target(other.get_target());
    }
    return(*this);
}