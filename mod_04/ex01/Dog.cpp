/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:55:54 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/21 13:47:20 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Dog.hpp"

//DEFAULT CONSTRUCTOR
Dog::Dog(){setType("Dog"); _brain = new Brain(); std::cout<< GREEN_CL <<"Default dog constructor"<<std::endl << WHITE_CL;}

Dog::Dog(std::string* new_ideas): _brain(new Brain(new_ideas)){ setType("Dog"); std::cout << GREEN_CL << "Dog idea construct" << std::endl << WHITE_CL;}

//COPY CONSTRUCTOR
Dog::Dog(const Dog& new_object): Animal(new_object), _brain(nullptr){
	if (new_object._brain)
		_brain = new Brain(*new_object._brain);
	std::cout<< GREEN_CL <<"Copy dog constructor"<<std::endl << WHITE_CL;}

//DESTRUCTOR
Dog::~Dog(){delete _brain; std::cout<< GREEN_CL <<"Default dog destructor"<<std::endl << WHITE_CL;}

// Brain& Dog::get_brain() const{return (*this->_brain);}

//MEMBER FUNCTIONS
void	Dog::makeSound() const{std::cout<<"Woofwoof motherfucker"<<std::endl;}

//COPY ASSIGMENT OVERLOAD
Dog& Dog::operator=(const Dog& other){
    if (this != &other){
		this->type = other.type;
		delete _brain;
		_brain = new Brain(*other._brain);
	}
    return (*this);
}
