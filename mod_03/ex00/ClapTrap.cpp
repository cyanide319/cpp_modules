/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:29:37 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/07 14:44:51 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//DEFAULT CONSTRUCT
ClapTrap::ClapTrap():
_hit_point(10), _energy_point(10), _attack_damage(0), _name("Default"){
std::cout<< RED_CL <<"Default constructor"<<std::endl;}
//NAMED CONSTRUCT
ClapTrap::ClapTrap(std::string name):
_hit_point(10), _energy_point(10), _attack_damage(0){set_name(name);
std::cout<< RED_CL <<"Named constructor"<<std::endl;}
//COPY CONSTRUCT
ClapTrap::ClapTrap(const ClapTrap& new_object){*this = new_object;
std::cout<< RED_CL <<"Copy constructor"<<std::endl;}
//DESTRUCTOR
ClapTrap::~ClapTrap(){std::cout<< RED_CL <<"Destructor"<<std::endl;}

//SETTERS
void	ClapTrap::set_name(std::string new_val){this->_name = new_val;}
void	ClapTrap::set_hit_point(int new_val){this->_hit_point = new_val;}
void	ClapTrap::set_energy_point(int new_val){this->_energy_point = new_val;}
void	ClapTrap::set_attack_damage(int new_val){this->_attack_damage = new_val;}
//GETTERS
std::string	ClapTrap::get_name(void) const{return(this->_name);}
int	ClapTrap::get_hit_point(void) const{return(this->_hit_point);}
int	ClapTrap::get_energy_point(void) const{return(this->_energy_point);}
int	ClapTrap::get_attack_damage(void) const{return(this->_attack_damage);}

//MEMBER FUNCTIONS
void	ClapTrap::attack(const std::string& target){
	if(get_hit_point() > 0){
		if (get_energy_point() > 0){
				int energy = get_energy_point() - 1;
				set_energy_point(energy);
				std::cout<< WHITE_CL <<"Claptrap "<<get_name()<<" attacks "<<target<<", causing " \
				<<get_attack_damage()<<" points of damages!"<<std::endl;}
		else	std::cout<< RED_CL <<"Claptrap "<<get_name()<<" has no energy left!"<<std::endl; return;}
	else	std::cout<< RED_CL <<"Claptrap "<<get_name()<<" is dead!"<<std::endl; return;
}

void	ClapTrap::takeDamage(unsigned int amount){if (amount < 0)	amount = 0;
	std::cout<< WHITE_CL <<"Claptrap "<<get_name() \
	<<" receive "<<amount<<" points of damages!"<<std::endl;
	int total = get_hit_point() - amount;
	if (total < 0) total = 0;
	set_hit_point(total);
}

void	ClapTrap::beRepaired(unsigned int amount){
	if(get_hit_point() > 0){
		if (get_energy_point() > 0){
			int energy = get_energy_point() - 1;
			set_energy_point(energy);
			std::cout<< WHITE_CL <<"Claptrap "<<get_name()<<" is repaired for "<<amount<<" hit points!"<<std::endl;
			int total = get_hit_point() + amount;
			if (!(total < 10 && total >= 0)) total = 10;
			set_hit_point(total);}
		else	std::cout<< RED_CL <<"Claptrap "<<get_name()<<" has no energy left!"<<std::endl; return;}
	else	std::cout<< RED_CL <<"Claptrap "<<get_name()<<" is dead!"<<std::endl; return;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other){
		this->_name = other._name;
		this->_hit_point = other._hit_point;
		this->_energy_point = other._energy_point;
		this->_attack_damage = other._attack_damage;
	}
    return (*this);
}
