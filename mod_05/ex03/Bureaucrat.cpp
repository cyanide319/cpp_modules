/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:12:21 by tristan           #+#    #+#             */
/*   Updated: 2023/05/23 16:33:30 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//DEFAULT CONSTRUCT
Bureaucrat::Bureaucrat(): _name("default"), _grade(150){}

//NAMED CONSTRUCT
Bureaucrat::Bureaucrat(std::string name, int grade): _name(name){
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	set_grade(grade);
}

//COPY CONSTRUCT
Bureaucrat::Bureaucrat(const Bureaucrat& new_object): _name(new_object._name){*this = new_object;}

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


//FUNCTIONS
void	Bureaucrat::grade_up(){
	try{
		std::cout << BLUE_CL << _name << " was grade: " << _grade << WHITE_CL << std::endl;
		this->set_grade(_grade - 1);
	}
	catch(const Bureaucrat::GradeTooHighException& e){
		std::cerr << e.what();
		std::cout << BLUE_CL << _name << " is still grade: " << _grade << WHITE_CL << std::endl;
		return ;
	}
	std::cout << BLUE_CL << _name << " is up to grade: " << _grade << WHITE_CL << std::endl;
	
}

void	Bureaucrat::grade_down(){
	try{
		std::cout << GREEN_CL << _name << " was grade: " << _grade << WHITE_CL << std::endl;
		this->set_grade(_grade + 1);
	}
	catch(const Bureaucrat::GradeTooLowException& e){
		std::cerr << e.what();
		std::cout << GREEN_CL << _name << " is still grade: " << _grade << WHITE_CL << std::endl;
		return ;
	}
	std::cout << GREEN_CL << _name << " is down to grade: " << _grade << WHITE_CL << std::endl;
	
}

void	Bureaucrat::signForm(Form& form){
	try{
		int ret;
		ret = form.beSigned(*this);
		if (ret == 0)
			std::cout << _name << " signed the " << form.get_name() << " form successfully!" << std::endl;
		if (ret == 2)
			std::cout << "The " << form.get_name() << " form was already signed!" << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << _name << " couldn't sign the " << form.get_name()<< " form because: " << e.what() << '\n';
	}
	
}

void	Bureaucrat::executeForm(Form& form){
	try{
		int ret;
		ret = form.beExecuted(*this);
		if (ret == 0)
			std::cout << _name << " executed the " << form.get_name() << " form successfully!" << std::endl;
		if (ret == 2)
			std::cout << "The " << form.get_name() << " form need to be signed!" << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << _name << " couldn't execute the " << form.get_name()<< " form because: " << e.what() << '\n';
	}
	
}

//EXCEPTIONS TRHOWS
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

std::ostream&   operator<<(std::ostream& output, const Bureaucrat& bureaucrat){
	output << bureaucrat.get_name() << ", bureaucrat grade " << bureaucrat.get_grade();
	return (output);
}
