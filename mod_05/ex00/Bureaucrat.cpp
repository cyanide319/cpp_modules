/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:12:21 by tristan           #+#    #+#             */
/*   Updated: 2023/05/17 18:04:36 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//DEFAULT CONSTRUCT
Bureaucrat::Bureaucrat(std::string name, int grade): _name(name){
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	set_grade(grade);
}

//COPY CONSTRUCT
Bureaucrat::Bureaucrat(const Bureaucrat& new_object): _name(new_object._name){}

//DEFAULT DESTRUCT
Bureaucrat::~Bureaucrat(){}


//SETTER
void	Bureaucrat::set_grade(int new_val){
	if (new_val < 1){
		throw Bureaucrat::GradeTooHighException();
		return ;
	}
	else if (new_val > 150){
		throw Bureaucrat::GradeTooLowException();
		return ;
	}
	this->_grade = new_val;
}
//GETTER
std::string	Bureaucrat::get_name(void) const{return(this->_name);}
int			Bureaucrat::get_grade(void) const{return(this->_grade);}

void	Bureaucrat::grade_up(){
	try{
		std::cout << _name << " was grade: " << _grade << std::endl;
		this->set_grade(_grade - 1);
	}
	catch(const Bureaucrat::GradeTooHighException& e){
		std::cerr << e.what();
		std::cout << _name << " is still grade: " << _grade << std::endl;
		return ;
	}
	std::cout << _name << " is up to grade: " << _grade << std::endl;
	
}

void	Bureaucrat::grade_down(){
	try{
		std::cout << _name << " was grade: " << _grade << std::endl;
		this->set_grade(_grade + 1);
	}
	catch(const Bureaucrat::GradeTooLowException& e){
		std::cerr << e.what();
		std::cout << _name << " is still grade: " << _grade << std::endl;
		return ;
	}
	std::cout << _name << " is down to grade: " << _grade << std::endl;
	
}



const char*	Bureaucrat::GradeTooHighException::what() const throw(){
	return ("The grade is too high.\n");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw(){
	return ("The grade is too low.\n");
}


Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    if(this != &other){
        this->_grade = other._grade;
    }
    return(*this);
}
