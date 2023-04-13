/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:35:32 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/13 11:45:15 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//DEFAULT CONSTRUCT
DiamondTrap::DiamondTrap(): ClapTrap("DiamondTrap_clap_name"){
	this->_name = "DiamondTrap";
	this->ClapTrap::_name = "DiamondTrap_clap_name";
	this->_hit_point = FragTrap::_frag_hit_point;
	this->_energy_point = ScavTrap::_scav_energy_point;
	this->_attack_damage = FragTrap::_frag_attack_damage;
	set_max_hit_point(100);
	std::cout<< RED_CL <<"DiamondTrap Default constructor"<<std::endl;}
//NAMED CONSTRUCT
DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"){
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->_hit_point = FragTrap::_frag_hit_point;
	this->_energy_point = ScavTrap::_scav_energy_point;
	this->_attack_damage = FragTrap::_frag_attack_damage;
	std::cout<< RED_CL <<"DiamondTrap Named constructor"<<std::endl;}
//COPY CONSTRUCT
DiamondTrap::DiamondTrap(const DiamondTrap& new_object){*this = new_object;
	std::cout<< RED_CL <<"DiamondTrap Copy constructor"<<std::endl;}
//DESTRUCTOR
DiamondTrap::~DiamondTrap(){std::cout<< RED_CL <<"DiamondTrap Destructor"<<std::endl;}

//SETTERS
void	DiamondTrap::set_name(std::string new_val){this->_name = new_val; this->ClapTrap::_name = new_val + "_clap_name";}
//GETTERS
std::string	DiamondTrap::get_name(void) const{return(this->_name);}

//MEMBER FUNCTIONS
void	DiamondTrap::whoAmI(){
		if(get_hit_point() > 0){
		if (get_energy_point() > 0){
				int energy = get_energy_point() - 1;
				set_energy_point(energy);
				std::cout<< WHITE_CL <<"I am "<<this->_name<<"!"<<std::endl;
				std::cout<< WHITE_CL <<"And my claptrap name is "<<this->ClapTrap::_name<<"!"<<std::endl;}
		else	std::cout<< RED_CL <<get_type()<<get_name()<<" has no energy left!"<<std::endl; return;}
	else	std::cout<< RED_CL <<get_type()<<get_name()<<" is dead!"<<std::endl; return;
}

//OPERATOR OVERLOAD
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other){
    std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
    if (this != &other){
		this->_name = other._name;
		this->_type = other._type;
		this->_hit_point = other._hit_point;
		this->_energy_point = other._energy_point;
		this->_attack_damage = other._attack_damage;
	}
    return (*this);
}