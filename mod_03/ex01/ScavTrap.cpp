/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:26:31 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/04/11 16:01:13 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ScavTrap.hpp"

//DEFAULT CONSTRUCT
ScavTrap::ScavTrap(){
	set_hit_point(100); set_max_hit_point(100); set_energy_point(50); set_attack_damage(20);
	set_guard_mode(false); set_name("Default"); set_type("Scavtrap ");
	std::cout<< RED_CL <<"ScavTrap Default constructor"<<std::endl;}
//NAMED CONSTRUCT
ScavTrap::ScavTrap(std::string name){
set_hit_point(100); set_max_hit_point(100); set_energy_point(50); set_attack_damage(20);
set_guard_mode(false); set_name(name); set_type("Scavtrap ");
std::cout<< RED_CL <<"ScavTrap Named constructor"<<std::endl;}
//COPY CONSTRUCT
ScavTrap::ScavTrap(const ScavTrap& new_object){*this = new_object;
std::cout<< RED_CL <<"ScavTrap Copy constructor"<<std::endl;}
//DESTRUCTOR
ScavTrap::~ScavTrap(){std::cout<< RED_CL <<"ScavTrap Destructor"<<std::endl;}

//SETTERS
void	ScavTrap::set_guard_mode(bool new_val){this->_guard_mode = new_val;}
//GETTERS
bool	ScavTrap::get_guard_mode(void) const{return(this->_guard_mode);}

//MEMBER FUNCTIONS
// void	ScavTrap::attack(const std::string& target){
// 	if(get_hit_point() > 0){
// 		if (get_energy_point() > 0){
// 			int energy = get_energy_point() - 1;
// 			set_energy_point(energy);
// 			std::cout<< WHITE_CL<<"ScavTrap "<<get_name()<<" attacks "<<target<<", causing " \
// 			<<get_attack_damage()<<" points of damages!"<<std::endl;}
// 		else	std::cout<< RED_CL<<get_name()<<" has no energy left!"<<std::endl; return;}
// 	else	std::cout<< RED_CL<<get_name()<<" is dead!"<<std::endl; return;
// }

void	ScavTrap::takeDamage(unsigned int amount){
	if (amount < 0)	amount = 0;
	if (get_guard_mode() == true){
		if (amount > _guard_dr)
			amount = (amount - _guard_dr);
		else
			amount = 0;
	}

	std::cout<< WHITE_CL <<get_name() \
	<<" receive "<<amount<<" points of damages!"<<std::endl;
	int total = (get_hit_point() - amount);
	if (total < 0) total = 0;
	set_hit_point(total);
}

void	ScavTrap::guardGate(){
	if(get_hit_point() > 0){
		if (get_energy_point() > 0){
				if (get_guard_mode() == false){
					int energy = get_energy_point() - 1;
					set_energy_point(energy);
					std::cout<< WHITE_CL<<get_name() \
					<<" is guarding the gate! What gate you ask? Doesn't matter!"<<std::endl;
					set_guard_mode(true);}	
				else{
					int energy = get_energy_point() - 1;
					set_energy_point(energy);
					std::cout<< WHITE_CL<<get_name() \
					<<" have stopped guarding the gate!"<<std::endl;
					set_guard_mode(false);}
				}
					
		else	std::cout<< RED_CL<<get_name()<<" has no energy left!"<<std::endl; return;}
	else	std::cout<< RED_CL<<get_name()<<" is dead!"<<std::endl; return;
}

//OPERATOR OVERLOAD
ScavTrap& ScavTrap::operator=(const ScavTrap& other){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other){
		this->_name = other._name;
		this->_type = other._type;
		this->_hit_point = other._hit_point;
		this->_max_hit_point = other._max_hit_point;
		this->_energy_point = other._energy_point;
		this->_attack_damage = other._attack_damage;
		this->_guard_mode = other._guard_mode;
	}
    return (*this);
}