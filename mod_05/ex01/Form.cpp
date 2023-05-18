/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:12:29 by tristan           #+#    #+#             */
/*   Updated: 2023/05/18 14:20:54 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//DEFAULT CONSTRUCT
Form::Form(std::string name, int to_sign, int to_exec): _name(name),
	_to_sign(to_sign), _to_exec(to_exec), _signed(false){
	if (to_sign < 1 || to_exec < 1)
		throw Form::GradeTooHighException();
	if (to_sign > 150 || to_exec > 150)
		throw Form::GradeTooLowException();
}

//COPY CONSTRCT
Form::Form(const Form& new_object):_name(new_object.get_name()),
	_to_sign(new_object.get_to_sign()), _to_exec(get_to_exec()){
	*this = new_object;
}

//DEFAULT DESTRUCT
Form::~Form(){}

//GETTERS
std::string Form::get_name(void) const {return(this->_name);}
int			Form::get_to_sign(void) const {return(this->_to_sign);}
int			Form::get_to_exec(void) const {return(this->_to_exec);}
bool		Form::get_signed(void) const {return(this->_signed);}

//SETTERS
void		Form::set_signed(bool new_val){this->_signed = new_val;}

//FUNCTIONS
int		Form::beSigned(Bureaucrat& bureaucrat){
	if (bureaucrat.get_grade() <= this->get_to_sign()){
		this->set_signed(true);
		return (0);
	}
	throw Form::GradeTooLowException();
	return (1);
}


//EXCEPTIONS TRHOWS
const char*	Form::GradeTooHighException::what() const throw(){
	return ("The grade is too high.\n");
}

const char*	Form::GradeTooLowException::what() const throw(){
	return ("The grade is too low.\n");
}

//OVERLOADS
Form& Form::operator=(const Form& other){
    if(this != &other){
        this->_signed = other._signed;
    }
    return(*this);
}

std::ostream&   operator<<(std::ostream& output, const Form& form){
	output << "The form called: " << form.get_name() 
	<< ", can be signed at grade " << form.get_to_sign()
	<< " and be executed at grade " << form.get_to_exec();
	if (form.get_signed() == false)
		output << ". It is currently unsigned.";
	else
		output << ". It is currently signed.";
	return (output);
}