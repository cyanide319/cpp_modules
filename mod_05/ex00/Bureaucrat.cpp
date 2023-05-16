/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:12:21 by tristan           #+#    #+#             */
/*   Updated: 2023/05/16 16:54:28 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//DEFAULT CONSTRUCT
Bureaucrat::Bureaucrat(std::string name): _name(name){}

//COPY CONSTRUCT
Bureaucrat::Bureaucrat(const Bureaucrat& new_object): _name(new_object._name){}

//DEFAULT DESTRUCT
Bureaucrat::~Bureaucrat(){}

void		Bureaucrat::set_grade(int new_val){
	try{
		if(new_val < 1)
			throw Bureaucrat::GradeTooHighException(new_val);
		if(new_val > 150)
			throw Bureaucrat::GradeTooLowException(new_val);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

std::string	Bureaucrat::get_name(void) const{return(this->_name);}
int			Bureaucrat::get_grade(void) const{return(this->_grade);}



int    Bureaucrate::GradeTooHighException(int wrongGrade){
	std::cout << "The grade " << wrongGrade << " is too high." << std::endl;
	return (1);
}

int    Bureaucrate::GradeTooLowException(int wrongGrade){
	std::cout << "The grade " << wrongGrade << " is too low." << std::endl;
	return (1);
	
}


Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    if(this != &other){
        this->_grade = other._grade;
    }
    return(*this);
}
