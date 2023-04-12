/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:35:32 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/12 19:15:39 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//DEFAULT CONSTRUCT
DiamondTrap::DiamondTrap(): FragTrap(), ScavTrap(), ClapTrap("DiamondTrap_clap_name"){
	this->_name = ClapTrap::_name;
	this->_hit_point = FragTrap::_frag_hit_point;
	this->_energy_point = ScavTrap::_scav_energy_point;
	this->_attack_damage = FragTrap::_frag_attack_damage;
	std::cout<< RED_CL <<"DiamondTrap Default constructor"<<std::endl;}
//NAMED CONSTRUCT
DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"){
	this->_name = ClapTrap::_name;
	ClapTrap::_name = name + "_clap_name";
	this->_hit_point = FragTrap::_frag_hit_point;
	this->_energy_point = ScavTrap::_scav_energy_point;
	this->_attack_damage = FragTrap::_frag_attack_damage;
	std::cout<< RED_CL <<"DiamondTrap Named constructor"<<std::endl;}
//COPY CONSTRUCT
DiamondTrap::DiamondTrap(const DiamondTrap& new_object){*this = new_object;
	std::cout<< RED_CL <<"DiamondTrap Copy constructor"<<std::endl;}
//DESTRUCTOR
DiamondTrap::~DiamondTrap(){std::cout<< RED_CL <<"DiamondTrap Destructor"<<std::endl;}



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