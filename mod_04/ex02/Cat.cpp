/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:48:30 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/25 13:20:58 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Cat.hpp"

//DEFAULT CONSTRUCTOR
Cat::Cat(): _brain(new Brain){ setType("Cat"); std::cout<< RED_CL <<"Default cat constructor"<<std::endl << WHITE_CL;}

Cat::Cat(std::string* new_ideas): _brain(new Brain(new_ideas)){ setType("Cat"); std::cout<< RED_CL <<"Idea cat constructor"<<std::endl << WHITE_CL;}
//COPY CONSTRUCTOR
Cat::Cat(const Cat& new_object): Animal(new_object), _brain(nullptr){
	if (new_object._brain)
		_brain = new Brain(*new_object._brain);
	std::cout<< RED_CL <<"Copy cat constructor"<<std::endl << WHITE_CL;}

//DESTRUCTOR
Cat::~Cat(){delete _brain; std::cout<< RED_CL <<"Default cat destructor"<<std::endl << WHITE_CL;}

Brain& Cat::get_brain() const{return (*this->_brain);}

//MEMBER FUNCTIONS
void	Cat::makeSound() const{std::cout<<"Meowmeow caliss"<<std::endl;}

//COPY ASSIGMENT OVERLOAD
Cat& Cat::operator=(const Cat& other){
    if (this != &other){
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
    return (*this);
}
