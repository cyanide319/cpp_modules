/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoin <tbeaudoin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:47:38 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/19 18:24:03 by tbeaudoin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Contact.hpp"

Contact::Contact(void){}

Contact::~Contact(void){}

std::string	Contact::get_first_name()  const{
	return (_first_name);
}

std::string Contact::get_last_name()  const{
	return (_last_name);
}

std::string Contact::get_nickname()  const{
	return (_nickname);
}

std::string Contact::get_phone_number() const{
	return (_phone_number);
}

std::string Contact::get_dark_secret() const{
	return (_dark_secret);
}

void	Contact::set_first_name(const std::string new_val){
	_first_name = new_val;
}
void	Contact::set_last_name(const std::string new_val){
	_last_name = new_val;
}
void	Contact::set_nickname(const std::string new_val){
	_nickname = new_val;
}
void	Contact::set_phone_number(const std::string new_val){
	_phone_number = new_val;
}
void	Contact::set_dark_secret(const std::string new_val){
	_dark_secret = new_val;
}