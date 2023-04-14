/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:50:21 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/14 12:51:09 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"WrongCat.hpp"

//DEFAULT CONSTRUCTOR
WrongCat::WrongCat(){setType("WrongCat");}

//COPY CONSTRUCTOR
WrongCat::WrongCat(const WrongCat& new_object){*this = new_object;}

//DESTRUCTOR
WrongCat::~WrongCat(){}

//COPY ASSIGMENT OVERLOAD
WrongCat& WrongCat::operator=(const WrongCat& other){
    if (this != &other){
		this->type = other.type;
	}
    return (*this);
}
