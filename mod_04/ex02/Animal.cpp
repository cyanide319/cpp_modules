/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:21:05 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/20 17:28:37 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Animal.hpp"

//DEFAULT CONSTRUCTOR
Animal::Animal(){std::cout<< BLUE_CL <<"Default animal constructor"<<std::endl << WHITE_CL;}

//COPY CONSTRUCTOR
Animal::Animal(const Animal& new_object){*this = new_object; std::cout<< BLUE_CL <<"Copy animal constructor"<<std::endl << WHITE_CL;}

//DESTRUCTOR
Animal::~Animal(){std::cout<< BLUE_CL <<"Default animal destructor"<<std::endl << WHITE_CL;}

//GETTER
std::string	Animal::getType() const{return (type);}
//SETTER
void	Animal::setType(std::string new_val){this->type = new_val;}

//MEMBER FUNCTIONS
void	Animal::makeSound() const{std::cout<<"Whatever"<<std::endl;}

//COPY ASSIGMENT OVERLOAD
Animal& Animal::operator=(const Animal& other){
    if (this != &other){
		this->type = other.type;
	}
    return (*this);
}
