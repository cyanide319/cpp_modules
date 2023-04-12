/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 18:54:46 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/11 19:11:29 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"FragTrap.hpp"

//DEFAULT CONSTRUCT
FragTrap::FragTrap(){
	set_hit_point(100); set_max_hit_point(100); set_energy_point(100); set_attack_damage(30);
	set_name("FragTrap"); set_type("Fragtrap ");
	std::cout<< RED_CL <<"FragTrap Default constructor"<<std::endl;}
//NAMED CONSTRUCT
FragTrap::FragTrap(std::string name){
	set_hit_point(100); set_max_hit_point(100); set_energy_point(100); set_attack_damage(30);
	set_name(name); set_type("Fragtrap ");
	std::cout<< RED_CL <<"FragTrap Named constructor"<<std::endl;}
//COPY CONSTRUCT
FragTrap::FragTrap(const FragTrap& new_object){*this = new_object;
std::cout<< RED_CL <<"FragTrap Copy constructor"<<std::endl;}
//DESTRUCTOR
FragTrap::~FragTrap(){std::cout<< RED_CL <<"FragTrap Destructor"<<std::endl;}

void	FragTrap::highFivesGuys(void){
	if(get_hit_point() > 0){
		if (get_energy_point() > 0){
				int energy = get_energy_point() - 1;
				set_energy_point(energy);
				std::cout<< WHITE_CL<<get_name() \
				<<" is waiting for a high five from it friend!" \
				"What kind of monster refuse a high five?"<<std::endl;}
		else	std::cout<< RED_CL<<get_name()<<" has no energy left!"<<std::endl; return;}
	else	std::cout<< RED_CL<<get_name()<<" is dead!"<<std::endl; return;
}

//OPERATOR OVERLOAD
FragTrap& FragTrap::operator=(const FragTrap& other){
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if (this != &other){
		this->_name = other._name;
		this->_type = other._type;
		this->_hit_point = other._hit_point;
		this->_max_hit_point = other._max_hit_point;
		this->_energy_point = other._energy_point;
		this->_attack_damage = other._attack_damage;
	}
    return (*this);
}