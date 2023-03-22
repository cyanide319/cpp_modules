/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:56:14 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/22 18:04:51 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"HumanB.hpp"

HumanB::HumanB(std::string name, Weapon weapon) {
	HumanB::setName(name);
	HumanB::setWeapon(weapon);
}

HumanB::HumanB(std::string name) {
	HumanB::setName(name);
	HumanB::setName("bare fists");
}

HumanB::~HumanB() {}

std::string	HumanB::getName() const{
	return (name);
}

Weapon HumanB::getWeapon() const{
	return (weapon);
}

void HumanB::setName(const std::string new_val){
	name = new_val;
}

void	HumanB::setWeapon(const Weapon new_val){
	weapon = new_val;
}

void	HumanB::attack(){
	std::string _weapon = weapon.getType();
	
	std::cout << HumanB::getName()  << " attack with their " << _weapon << std::endl;
}
