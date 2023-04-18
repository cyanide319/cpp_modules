/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:48:30 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/14 14:17:17 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Cat.hpp"

//RED

//DEFAULT CONSTRUCTOR
Cat::Cat(){setType("Cat");std::cout<< RED_CL <<"Default cat constructor"<<std::endl << WHITE_CL;}

//COPY CONSTRUCTOR
Cat::Cat(const Cat& new_object){*this = new_object;std::cout<< RED_CL <<"Copy cat constructor"<<std::endl << WHITE_CL;}

//DESTRUCTOR
Cat::~Cat(){std::cout<< RED_CL <<"Default cat destructor"<<std::endl << WHITE_CL;}

//MEMBER FUNCTIONS
void	Cat::makeSound() const{std::cout<< RED_CL <<"Meowmeow caliss"<<std::endl << WHITE_CL;}

//COPY ASSIGMENT OVERLOAD
Cat& Cat::operator=(const Cat& other){
    if (this != &other){
		this->type = other.type;
	}
    return (*this);
}
