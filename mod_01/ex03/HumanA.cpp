/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:42:12 by tbeaudoi          #+#    #+#             */
/*   Updated: 2023/03/22 18:04:11 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon) {
	HumanA::setName(name);
	HumanA::setWeapon(weapon);
}

HumanA::~HumanA() {}

std::string	HumanA::getName() const{
	return (name);
}

Weapon HumanA::getWeapon() const{
	return (weapon);
}

void HumanA::setName(const std::string new_val){
	name = new_val;
}

void	HumanA::setWeapon(const Weapon new_val){
	weapon = new_val;
}

void	HumanA::attack(){
	std::string _weapon = weapon.getType();
	
	std::cout << HumanA::getName()  << " attack with their " << _weapon << std::endl;
}
