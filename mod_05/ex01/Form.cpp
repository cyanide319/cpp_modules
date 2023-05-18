/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tristan <tristan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:12:29 by tristan           #+#    #+#             */
/*   Updated: 2023/05/18 13:30:29 by tristan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int to_sign, int to_exec): _name(name),
	_to_sign(to_sign), _to_exec(to_exec), _signed(false){}

Form::Form(const Form& new_object):_name(new_object.get_name()),
	_to_sign(new_object.get_to_sign()), _to_exec(get_to_exec()){
	*this = new_object;
}

Form::~Form(){}

std::string Form::get_name(void) const {return(this->_name);}
int			Form::get_to_sign(void) const {return(this->_to_sign);}
int			Form::get_to_exec(void) const {return(this->_to_exec);}
bool		Form::get_signed(void) const {return(this->_signed);}

void		Form::set_signed(bool new_val){this->_signed = new_val;}


Form& Form::operator=(const Form& other){
    if(this != &other){
        this->_signed = other._signed;
    }
    return(*this);
}