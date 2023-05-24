/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:27:57 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/05/24 17:45:33 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PresidentialPardonForm.hpp"

//DEFAULT CONSTRUCT
PresidentialPardonForm::PresidentialPardonForm():
Form("Presidential Pardon", 25, 5){set_target("default");}

//NAMED CONSTRUCT
PresidentialPardonForm::PresidentialPardonForm(std::string target):
Form("Presidential Pardon", 25, 5){set_target(target);}

//COPY CONSTRUCT
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& new_object):
Form(new_object.get_name(), 25, 5){
	*this = new_object;
}

//DEFAULT DESTRUCT
PresidentialPardonForm::~PresidentialPardonForm(){}

int	PresidentialPardonForm::execute(const Bureaucrat& bureaucrat) const{
	if (bureaucrat.get_grade() <= this->get_to_sign()){
		if (get_signed() == true){
		std::cout << "By the surpreme autority of the God Emperor Zaphod Beeblebrox, you, "
			<< get_target() <<  ", have been pardonned. Now proceed with the execution." << std::endl;
			return (0);
		}
		else{
			return(2);
		}
	}
	throw Form::GradeTooLowException();
	return (1);
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	if (this != &other){
        this->set_signed(other.get_signed());
		this->set_target(other.get_target());
    }
    return(*this);
}